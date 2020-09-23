#include"Dictionary.h"

#include<iostream>
#include <fstream>
#include <utility>

using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;

Node::Node(string _key, string _value, Node *_next = nullptr) :key(std::move(_key)), value(std::move(_value)), next(_next) {}

Node::~Node() {
    delete next;
}

Dictionary::~Dictionary() {
    delete node;
}

void Dictionary::add_to_head(string key, string value) {
    node = new Node(std::move(key), std::move(value), node);
}

string Dictionary::to_lower(string str) {
    for (auto &c : str) {
        c = tolower(c);
    }
    return str;
}

bool Dictionary::is_empty() {
    return node == nullptr;
}

void Dictionary::put(string key, const string& value) {
    key = Dictionary::to_lower(key);

    if(is_empty() || key.compare(node->key) < 0) {
        add_to_head(key, value);
    } else {
        Node *current = node;

        while(current->next && key.compare(current->key) > 0) {
            current = current->next;
        }

        if(key == current->key) {
            current->value = value;
        } else {
            current->next = new Node(key, value, current->next);
        }
    }
}


string Dictionary::get(string key) {
    key = to_lower(key);
    Node *current = node;

    while(current && current->key != key) {
        current = current->next;
    }

    return current ? current->value : "";
}

bool Dictionary::update(string key, string value) {
    key = to_lower(key);
    Node *current = node;

    while(current && current->key != key) {
        current = current->next;
    }

    if(current) {
        current->value = std::move(value);
        return true;
    }

    return false;
}

bool Dictionary::remove(string key) {
    if(is_empty()) {
        return false;
    }

    key = to_lower(key);
    bool success = false;

    if(key == node->key) {
        Node *temp = node->next;

        if (temp == nullptr) {
            delete node;
            node = nullptr;
        } else {
            node->next = nullptr;
            delete node;
            node = temp;
        }
        success = true;
    } else {
        Node *current = node;

        while (current->next && current->next->key != key) {
            current = current->next;
        }

        if (current != nullptr) {
            Node *temp = current->next;

            if(current->next) {
                current->next = current->next->next;
                temp->next = nullptr;
            } else {
                current->next = nullptr;
            }

            delete temp;
            success = true;
        }
    }

    return success;
}

unsigned int Dictionary::count() {
    Node *current = node;
    unsigned int counter = 0;

    while(current) {
        counter++;
        current = current->next;
    }

    return counter;
}

string * Dictionary::keys(unsigned int &length) {
    length = count();
    auto *values = new string[length];
    Node *current = node;
    unsigned int counter = 0;

    while(current) {
        values[counter++] = current->key;
        current = current->next;
    }

    return values;
}

string * Dictionary::values(unsigned int &length) {
    length = count();
    auto *values = new string[length];
    Node *current = node;
    unsigned int counter = 0;

    while(current) {
        values[counter++] = current->value;
        current = current->next;
    }

    return values;
}

void Dictionary::print() {
    Node *current = node;

    while(current) {
        cout << current->key << ": " << current->value << "\n";
        current = current->next;
    }
}