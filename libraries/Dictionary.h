#pragma once

#include <iostream>
#include <utility>

using std::string;

class Dictionary {
private:
    string key = "";

    string value = "";

    Dictionary *next = nullptr;

    unsigned int length = 0;

    void add_rec(const string &key, const string &value);

    string toLower(string str);

public:
    Dictionary();

    Dictionary(string _key, string _value);

    ~Dictionary();

    void add(string key, const string &value);

    string get(string key);

    void update(string key, const string &value);

    void remove(string key);

    bool isEmpty();

    unsigned int count();

    void print();

    string *keys(unsigned int &length);

    string *values(unsigned int &length);
};