#include "polynomial.h"
#include <iostream>
using namespace std;

int main()
{
    Polynomial a(5);
    Polynomial b(2, 3.0);
    Polynomial c(2, 3.0);

    b = b + 5;
    c = c + a;
    b.printPolynomial();
}