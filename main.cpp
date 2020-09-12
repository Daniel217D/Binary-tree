#include <iostream>

#include "libraries/Dictionary.h"

using std::cout;
using std::string;

int main() {
    auto *d = new Dictionary();
    d->add("Dog", "Собака");
    d->add("Dog", "Собакен");
    d->add("DOg", "Собачка");
    d->add("Cat", "Кошка");
    d->add("Bed", "Кровать");

    d->print();
    d->remove("aSS");
    d->print();

    return 0;
}
