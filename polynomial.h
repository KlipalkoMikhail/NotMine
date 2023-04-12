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
    Polynomial operator+(const Polynomial &other) const;
    void operator+=(const Polynomial &other);
    Polynomial operator-(const Polynomial &other) const;
    void operator-=(const Polynomial &other);
    Polynomial operator*(const Polynomial &other) const;
    void operator*=(const Polynomial &other);
    Polynomial operator+(double constant) const;
    void operator+=(double constant);
    Polynomial operator-(double constant) const;
    void operator-=(double constant);
    Polynomial operator*(double constant) const;
    void operator*=(double constant);
    double operator()(double value_of_variable) const;
    bool operator==(const Polynomial &other) const;
    bool operator!=(const Polynomial &other) const;
    size_t get_power() const;

    void print();
};