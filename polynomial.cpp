#include "polynomial.h"
#include "my_exception.h"
#include <iostream>
#include <math.h>
using namespace std;
int i, k, l;
double temporary_variable, polynomial_value;
 //конструкторы
Polynomial::Polynomial() 
{
    this->power = 0;
    this->polynomial = new double[1];
    polynomial[0] = 0;
}

Polynomial::Polynomial(double coefficient) 
{
    this->power = 0;
    this->polynomial = new double[1];
    polynomial[0] = coefficient;
}

Polynomial::Polynomial(size_t power, double coefficient) 
{
    try{
        this->power = power;
        this->polynomial = new double[power + 1];
        for (i = 0; i < power; i++)
            polynomial[i] = 0;
        polynomial[power] = coefficient;
    } catch(MyException &message){
        throw new MyException(EC_MEMORY, "Bad memory allocation\n");
    }
}

Polynomial::Polynomial(const Polynomial &other) 
{
    try{
        this->power = other.power;
        this->polynomial = new double[this->power + 1];
        for(i = 0; i <= this->power; i++)
            this->polynomial[i] = other.polynomial[i];
    } catch(MyException &message){
        throw new MyException(EC_MEMORY, "Bad memory allocation\n");
    }
}

//методы
void Polynomial::operator=(const Polynomial &other)
{
    try{
        this->power = other.power;
        delete this->polynomial;
        this->polynomial = new double[this->power + 1];
        for(i = 0; i <= this->power; i++)
        this->polynomial[i] = other.polynomial[i];
    } catch(MyException &message){
        throw new MyException(EC_MEMORY, "Bad memory allocation\n");
    }
}

Polynomial Polynomial::operator+(const Polynomial &other)
{
    try{
        Polynomial temporary_polynomial;
        Polynomial resulting_polynomial;

        temporary_polynomial.power = fmax(this->power, other.power);
        temporary_variable = fmin(this->power, other.power);
        temporary_polynomial.polynomial = new double[temporary_polynomial.power+1];

        for (i = 0; i <= temporary_variable; i++)
            temporary_polynomial.polynomial[i] = this->polynomial[i] + other.polynomial[i];

        if(this->power == temporary_polynomial.power)
            for (i = temporary_variable + 1; i <= temporary_polynomial.power; i++)
                temporary_polynomial.polynomial[i] = this->polynomial[i];
        else
            for (i = temporary_variable + 1; i <= temporary_polynomial.power; i++)
                temporary_polynomial.polynomial[i] = other.polynomial[i];

        if (fabs(temporary_polynomial.polynomial[temporary_polynomial.power]) < 1e-100)
        {
            i = temporary_polynomial.power;
            while(fabs(temporary_polynomial.polynomial[i]) < 1e-100 && i != 0)
                i--;
            if (i != 0)
            {
                resulting_polynomial.power = i;
                resulting_polynomial.polynomial = new double[resulting_polynomial.power + 1];
                for (i = 0; i <= resulting_polynomial.power; i++)
                    resulting_polynomial.polynomial[i] = temporary_polynomial.polynomial[i];
            }
            return resulting_polynomial;
        }
        else
            return temporary_polynomial;
    } catch(MyException &message){
        throw new MyException(EC_MEMORY, "Bad memory allocation\n");
    }
}

void Polynomial::operator+=(const Polynomial &other)
{
    try{
        Polynomial temporary_polynomial;
        Polynomial resulting_polynomial;

        temporary_polynomial.power = fmax(this->power, other.power);
        temporary_variable = fmin(this->power, other.power);
        temporary_polynomial.polynomial = new double[temporary_polynomial.power+1];

        for (i = 0; i <= temporary_variable; i++)
            temporary_polynomial.polynomial[i] = this->polynomial[i] + other.polynomial[i];

        if(this->power == temporary_polynomial.power)
            for (i = temporary_variable + 1; i <= temporary_polynomial.power; i++)
                temporary_polynomial.polynomial[i] = this->polynomial[i];
        else
            for (i = temporary_variable + 1; i <= temporary_polynomial.power; i++)
                temporary_polynomial.polynomial[i] = other.polynomial[i];

        if (fabs(temporary_polynomial.polynomial[temporary_polynomial.power]) < 1e-100)
        {
            i = temporary_polynomial.power;
            while(fabs(temporary_polynomial.polynomial[i]) < 1e-100 && i != 0)
                i--;
            if (i != 0)
            {
                resulting_polynomial.power = i;
                resulting_polynomial.polynomial = new double[resulting_polynomial.power + 1];
                for (i = 0; i <= resulting_polynomial.power; i++)
                    resulting_polynomial.polynomial[i] = temporary_polynomial.polynomial[i];
            }
            *this = resulting_polynomial;
        }
        else
            *this = temporary_polynomial;
    } catch(MyException &message){
        throw new MyException(EC_MEMORY, "Bad memory allocation\n");
    }
}

Polynomial Polynomial::operator-(const Polynomial &other)
{
    try{
        Polynomial temporary_polynomial;
        Polynomial resulting_polynomial;

        temporary_polynomial.power = fmax(this->power, other.power);
        temporary_variable = fmin(this->power, other.power);
        temporary_polynomial.polynomial = new double[temporary_polynomial.power+1];

        for (i = 0; i <= temporary_variable; i++)
            temporary_polynomial.polynomial[i] = this->polynomial[i] - other.polynomial[i];

        if(this->power == temporary_polynomial.power)
            for (i = temporary_variable + 1; i <= temporary_polynomial.power; i++)
                temporary_polynomial.polynomial[i] = this->polynomial[i];
        else
            for (i = temporary_variable + 1; i <= temporary_polynomial.power; i++)
                temporary_polynomial.polynomial[i] = other.polynomial[i];

        if (fabs(temporary_polynomial.polynomial[temporary_polynomial.power]) < 1e-100)
        {
            i = temporary_polynomial.power;
            while(fabs(temporary_polynomial.polynomial[i]) < 1e-100 && i != 0)
                i--;
            if (i != 0)
            {
                resulting_polynomial.power = i;
                resulting_polynomial.polynomial = new double[resulting_polynomial.power + 1];
                for (i = 0; i <= resulting_polynomial.power; i++)
                    resulting_polynomial.polynomial[i] = temporary_polynomial.polynomial[i];
            }
            return resulting_polynomial;
        }
        else
            return temporary_polynomial;
    } catch(MyException &message){
        throw new MyException(EC_MEMORY, "Bad memory allocation\n");
    }
}

void Polynomial::operator-=(const Polynomial &other)
{
    Polynomial temporary_polynomial;
    Polynomial resulting_polynomial;

    temporary_polynomial.power = fmax(this->power, other.power);
    temporary_variable = fmin(this->power, other.power);
    temporary_polynomial.polynomial = new double[temporary_polynomial.power+1];

    for (i = 0; i <= temporary_variable; i++)
        temporary_polynomial.polynomial[i] = this->polynomial[i] - other.polynomial[i];

    if(this->power == temporary_polynomial.power)
        for (i = temporary_variable + 1; i <= temporary_polynomial.power; i++)
            temporary_polynomial.polynomial[i] = this->polynomial[i];
    else
        for (i = temporary_variable + 1; i <= temporary_polynomial.power; i++)
            temporary_polynomial.polynomial[i] = other.polynomial[i];

    if (fabs(temporary_polynomial.polynomial[temporary_polynomial.power]) < 1e-100)
    {
        i = temporary_polynomial.power;
        while(fabs(temporary_polynomial.polynomial[i]) < 1e-100 && i != 0)
            i--;
        if (i != 0)
        {
            resulting_polynomial.power = i;
            resulting_polynomial.polynomial = new double[resulting_polynomial.power + 1];
            for (i = 0; i <= resulting_polynomial.power; i++)
                resulting_polynomial.polynomial[i] = temporary_polynomial.polynomial[i];
        }
        *this = resulting_polynomial;
    }
    else
        *this = temporary_polynomial;
}

Polynomial Polynomial::operator*(const Polynomial &other)
{
    Polynomial product_of_polynomials(this->power + other.power, 0);
    for (i = 0; i <= product_of_polynomials.power; i++)
        for(k = 0; k <= this->power; k++)
            for(l = 0; l <= other.power; l++)
                if(k + l == i)
                    product_of_polynomials.polynomial[i] += this->polynomial[k]*other.polynomial[l];
                
    return product_of_polynomials;
}

void Polynomial::operator*=(const Polynomial &other)
{
    Polynomial product_of_polynomials(this->power + other.power, 0);
    for (i = 0; i <= product_of_polynomials.power; i++)
        for(k = 0; k <= this->power; k++)
            for(l = 0; l <= other.power; l++)
                if(k + l == i)
                    product_of_polynomials.polynomial[i] += this->polynomial[k]*other.polynomial[l];
                
    *this = product_of_polynomials;
}

//константы
Polynomial Polynomial::operator+(double constant)
{
    this->polynomial[0] += constant;
    return *this;
}

void Polynomial::operator+=(double constant)
{
    this->polynomial[0] += constant;
}

Polynomial Polynomial::operator-(double constant)
{
    this->polynomial[0] -= constant;
    return *this;
}

void Polynomial::operator-=(double constant)
{
    this->polynomial[0] -= constant;
}

Polynomial Polynomial::operator*(double constant)
{
    Polynomial temporary_polynomial = *this;

    if (fabs(constant) > 1e-100)
    {
        for(i = 0; i <= temporary_polynomial.power; i++)
            temporary_polynomial.polynomial[i] *= constant;
        return temporary_polynomial;
    }
    Polynomial zero_monomial;
    return zero_monomial;
}

void Polynomial::operator*=(double constant)
{
    if (fabs(constant) > 1e-100)
        for(i = 0; i <= this -> power; i++)
            this -> polynomial[i] *= constant;
    else
    {
        Polynomial zero_monomial;
        *this = zero_monomial;
    }
}

double Polynomial::operator()(double value_of_variable)
{
    polynomial_value = this->polynomial[this->power];
    for (i = 0; i <= (this -> power) - 1; i++)
        polynomial_value = polynomial_value * value_of_variable + this->polynomial[(this -> power) - 1 - i];

    return polynomial_value;
}

bool Polynomial::operator==(const Polynomial &other)
{
    if (this->power != other.power)
        return false;
    for (i = 0; i <= power; i++)
    {
        if (this->polynomial[i] != other.polynomial[i])
            return false;
    }
    return true;    
}

bool Polynomial::operator!=(const Polynomial &other)
{
    if (this->power != other.power)
        return true;
    for (i = 0; i <= power; i++)
    {
        if (this->polynomial[i] != other.polynomial[i])
            return true;
    }
    return false;      
}

size_t Polynomial::get_power()
{
    return power;
}

void Polynomial::printPolynomial() 
{
    for (size_t i = 0; i <= this->power; i++)
    {
        if (fabs(this->polynomial[i]) > 1e-100 && i != this->power && i != 0)
            cout << this->polynomial[i] << "x^" << i <<" + ";
        if (fabs(this->polynomial[i]) > 1e-100 && i == this->power && i != 0)
            cout << this->polynomial[i] << "x^" << i;
        if (fabs(this->polynomial[i]) > 1e-100 && i != this->power && i == 0)
            cout << this->polynomial[i] << " + ";
        if (i == this->power && i == 0)
            cout << this->polynomial[i];
    }
    cout << "\n";
}