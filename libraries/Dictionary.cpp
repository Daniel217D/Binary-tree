#include "Dictionary.h"

#include <iostream>
#include <utility>

using std::cout;
using std::string;

Dictionary::Dictionary() = default;

Dictionary::Dictionary(string _key, string _value) : key(std::move(_key)), value(std::move(_value)) {
}

Dictionary::~Dictionary() {
    delete this->next;
}

string Dictionary::toLower(string str) {
    for (auto &c : str) {
        c = tolower(c);
    }
    return str;
}

void Dictionary::add(string key, const string &value) {
    key = this->toLower(key);

    //Если список пуст
    if (this->isEmpty()) {
        this->key = key;
        this->value = value;
    } else {
        int compare = this->key.compare(key);

        //левее
        if (compare > 0) {
            auto temp = new Dictionary(this->key, this->value);
            temp->next = this->next;
            this->key = key;
            this->value = value;
            this->next = temp;
            //правее
        } else if (compare < 0) {
            if (this->next) {
                this->add_rec(key, value);
            } else {
                this->next = new Dictionary(key, value);
            }
        } else {
            this->value = value;
        }
    }
}

void Dictionary::add_rec(const string &key, const string &value) {
    if (!this->next) {
        this->next = new Dictionary(key, value);
    } else {
        int compare = this->next->key.compare(key);
        //левее
        if (compare > 0) {
            auto temp = new Dictionary(key, value);
            temp->next = this->next;
            this->next = temp;
            //правее
        } else if (compare < 0) {
            this->next->add_rec(key, value);
        } else {
            this->next->value = value;
        }
    }
}

string Dictionary::get(string key) {
    key = this->toLower(key);
    int compare = this->key.compare(key);
    string result;

    //правее
    if (compare < 0 && this->next) {
        return this->next->get(key);
    } else if (compare == 0) {
        result = this->value;
    }

    return result;
}

void Dictionary::update(string key,const string &value) {
    key = this->toLower(key);
    auto *current = this;

    while (current && current->key != key) {
        current = current->next;
    }

    if (current) {
        current->value = value;
    }
}

void Dictionary::remove(string key) {
    key = this->toLower(key);
    auto *current = this;
    Dictionary *prev = nullptr;

    while (current && current->key != key) {
        prev = current;
        current = current->next;
    }

    if (current) {
        if (prev) {
            prev->next = current->next;
            delete current;
        } else {
            if (current->next) {
                current->key = current->next->key;
                current->value = current->next->value;
                current->next = current->next->next;
            } else {
                current->key = "";
                current->value = "";
            }
        }
    }
}

bool Dictionary::isEmpty() {
    return this->key.empty() && this->value.empty() && !this->next;
}

unsigned int Dictionary::count() {
    unsigned int length = 0;

    if(!this->isEmpty()) {
        auto *current = this;
        do {
            length++;
            current = current->next;
        } while (current);
    }

    return length;
}

void Dictionary::print() {
    if (!this->isEmpty()) {
        auto *current = this;

        do {
            cout << current->key << ": " << current->value << "\n";
            current = current->next;
        } while (current);

        cout << "\n";
    }
}

string *Dictionary::keys(unsigned int &length) {
    length = this->count();
    auto *keys = new string[length];
    auto *current = this;

    for (int i = 0; i < length; ++i, current = current->next) {
        keys[i] = current->key;
    }

    return keys;
}

string *Dictionary::values(unsigned int &length) {
    length = this->count();
    auto *values = new string[length];
    auto *current = this;

    for (int i = 0; i < length; ++i, current = current->next) {
        values[i] = current->value;
    }

    return values;
}