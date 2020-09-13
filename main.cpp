#include <iostream>

#include "libraries/Dictionary.h"

using std::cout;
using std::string;

int main() {
    auto *d = new Dictionary();

    d->add("Dog", "Собака");
    d->add("Cat", "Кошка");
    d->add("Bed", "Кровать");
    d->print();

    d->add("dog", "Собакен");
    d->add("DOG", "Собачка");
    d->print();

    cout << "Dog - " << d->get("Dog") << "\n";
    cout << "Cat - " << d->get("Cat") << "\n";

    d->update("cat", "Кот");
    d->print();

    unsigned int length;
    string *values = d->keys(length);
    for (unsigned int i = 0; i < length; ++i) {
        cout << values[i] << " ";
    }
    cout << "\n";

    values = d->values(length);
    for (unsigned int i = 0; i < length; ++i) {
        cout << values[i] << " ";
    }
    cout << "\n\n";

    cout << "Количество: " << d->count() << "\n";
    d->remove("cat");
    d->print();
    cout << "Количество: " << d->count() << "\n";

    d->remove("bed");
    cout << "Пустой: " << (d->isEmpty() ? "Да" : "Нет") << "\n";
    d->remove("dog");
    cout << "Пустой: " << (d->isEmpty() ? "Да" : "Нет") << "\n";

    d->add("dependency", "Зависимость");

    delete d;
    return 0;
}
