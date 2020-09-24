#include <iostream>

#include "libraries/Dictionary.h"

using std::cout;
using std::string;

int main() {
    auto *d = new Dictionary("Dog", "Собака");

    d->put("Cat", "Кошка");
    d->put("Bed", "Кровать");
    cout << d->to_string();
    cout << "\n";

    d->put("dog", "Собакен");
    d->put("DOG", "Собачка");
    d->update("cat", "Кот");
    cout << d->to_string();
    cout << "\n";

    cout << "Dog - " << d->get("Dog") << "\n";
    cout << "Cat - " << d->get("Cat") << "\n";
    cout << "\n";

    unsigned int length;
    string *values = d->keys(length);
    for (unsigned int i = 0; i < length; ++i) {
        cout << values[i] << " ";
    }
    cout << "\n";
    delete[] values;

    values = d->values(length);
    for (unsigned int i = 0; i < length; ++i) {
        cout << values[i] << " ";
    }
    cout << "\n\n";

    cout << d->to_string();
    cout << "Количество: " << d->count() << "\n\n";
    d->remove("cat");
    cout << d->to_string();
    cout << "Количество: " << d->count() << "\n\n";

    d->remove("bed");
    cout << "Пустой: " << (d->is_empty() ? "Да" : "Нет") << "\n";
    d->remove("dog");
    cout << "Пустой: " << (d->is_empty() ? "Да" : "Нет") << "\n\n";

    delete d;
    return 0;
}
