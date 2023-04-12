#include "polynomial.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    double power;
    double coef;
    Polynomial a(5);
    Polynomial b(2, 3.0);
    Polynomial c(2, 3.0);
    Polynomial d(4, 2.5);

    // Проверка сложения
    a = a + b;
    a.print();

    // Проверка вычитания
    b = b - c;
    b.print();

    // Добавление константы
    b = b + 5;
    b.print();

    // Добавление константы
    b += 5;
    b.print();

    cout << "Print power and coefficient: ";
    cin >> power >> coef;

    assert(cin.fail() == 0);
}