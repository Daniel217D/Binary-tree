#pragma once

#include <iostream>

using std::string;

class Node {
private:
    string key;

    string value;

    Node *next;

    friend class Dictionary;

public:
    explicit Node(string _key, string _value, Node *_next);

    ~Node();
};

class Dictionary {
private:
    Node *node = nullptr;

    void add_to_head(string key, string value);

    static string to_lower(string str);
public:
    ~Dictionary();

    bool is_empty();

    void put(string key, const string& value);

    string get(string key);

    bool update(string key, string value);

    bool remove(string key);

    unsigned int count();

    string *keys(unsigned int &length);

    string *values(unsigned int &length);

    void print();
};
