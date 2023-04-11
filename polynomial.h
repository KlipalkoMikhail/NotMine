#include <iostream>
class Polynomial
{
private:
    double* polynomial;
    size_t power;

public:
    Polynomial();
    Polynomial(double coefficient);
    Polynomial(size_t power, double coefficient);
    Polynomial(const Polynomial &other);
    void operator=(const Polynomial &other);
    Polynomial operator+(const Polynomial &other);
    void operator+=(const Polynomial &other);
    Polynomial operator-(const Polynomial &other);
    void operator-=(const Polynomial &other);
    Polynomial operator*(const Polynomial &other);
    void operator*=(const Polynomial &other);
    Polynomial operator+(double constant);
    void operator+=(double constant);
    Polynomial operator-(double constant);
    void operator-=(double constant);
    Polynomial operator*(double constant);
    void operator*=(double constant);
    double operator()(double value_of_variable);
    bool operator==(const Polynomial &other);
    bool operator!=(const Polynomial &other);
    size_t get_power();

    friend void printPolynomial(Polynomial polynomial);
};