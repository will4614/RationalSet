#include "Rational.h"
#include <iostream>

Rational::Rational(int n, int d) : num(n), den(d) {}

Rational::Rational(int n) : num(n), den(1) {}

Rational::Rational() : num(0), den(1) {}

Rational::Rational(const Rational& r) : num(r.num), den(r.den) {}


Rational& Rational::operator=(const Rational& r) {
    num = r.num;
    den = r.den;
    return *this;
}

Rational& Rational::operator+=(const Rational& r) {
    num = num * r.den + den * r.num;
    den = den * r.den;
    return *this;
}

Rational& Rational::operator-=(const Rational& r) {
    num = num * r.den - den * r.num;
    den = den * r.den;
    return *this;
}

Rational& Rational::operator*=(const Rational& r) {
    num = num * r.num;
    den = den * r.den;
    return *this;
}

Rational& Rational::operator/=(const Rational& r) {
    num = num * r.den;
    den = den * r.num;
    return *this;
}

Rational Rational::operator-() const {
    return Rational(-num, den);
}

Rational Rational::operator+() const {
    return Rational(num, den);
}

Rational Rational::operator++() {
    num += den;
    return *this;
}

Rational Rational::operator++(int) {
    Rational temp(*this);
    num += den;
    return temp;
}

Rational Rational::operator--() {
    num -= den;
    return *this;
}

Rational Rational::operator--(int) {
    Rational temp(*this);
    num -= den;
    return temp;
}

std::ostream& operator<<(std::ostream& os, const Rational& r) {
    os << r.num << "/" << r.den;
    return os;
}

std::istream& operator>>(std::istream& is, Rational& r) {
    is >> r.num >> r.den;
    return is;
}

Rational operator-(const Rational& r1, const Rational& r2) {
    Rational temp(r1);
    temp -= r2;
    return temp;
}

Rational operator*(const Rational& r1, const Rational& r2) {
    Rational temp(r1);
    temp *= r2;
    return temp;
}

Rational operator/(const Rational& r1, const Rational& r2) {
    Rational temp(r1);
    temp /= r2;
    return temp;
}

bool operator==(const Rational& r1, const Rational& r2) {
    return r1.num * r2.den == r1.den * r2.num;
}

bool operator!=(const Rational& r1, const Rational& r2) {
    return !(r1 == r2);
}

bool operator<(const Rational& r1, const Rational& r2) {
    return r1.num * r2.den < r1.den * r2.num;
}

bool operator>(const Rational& r1, const Rational& r2) {
    return r2 < r1;
}

bool operator<=(const Rational& r1, const Rational& r2) {
    return !(r1 > r2);
}

bool operator>=(const Rational& r1, const Rational& r2) {
    return !(r1 < r2);
}

Rational operator+(const Rational& r1, const Rational& r2) {
    Rational temp(r1);
    temp += r2;
    return temp;
}

// Path: src/Rational.h
#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational {
    friend std::ostream& operator<<(std::ostream& os, const Rational& r);
    friend std::istream& operator>>(std::istream& is, Rational& r);
    friend Rational operator-(const Rational& r1, const Rational& r2);
    friend Rational operator*(const Rational& r1, const Rational& r2);
    friend Rational operator/(const Rational& r1, const Rational& r2);
    friend bool operator==(const Rational& r1, const Rational& r2);
    friend bool operator!=(const Rational& r1, const Rational& r2);
    friend bool operator<(const Rational& r1, const Rational& r2);
    friend bool operator>(const Rational& r1, const Rational& r2);
    friend bool operator<=(const Rational& r1, const Rational& r2);
    friend bool operator>=(const Rational& r1, const Rational& r2);
    friend Rational operator+(const Rational& r1, const Rational& r2);

public:

    Rational(int n, int d);
    Rational(int n);
    Rational();
    Rational(const Rational& r);

    Rational& operator=(const Rational& r);
    Rational& operator+=(const Rational& r);
    Rational& operator-=(const Rational& r);
    Rational& operator*=(const Rational& r);
    Rational& operator/=(const Rational& r);
    Rational operator-() const;
    Rational operator+() const;
    Rational operator++();
    Rational operator++(int);
    Rational operator--();
    Rational operator--(int);

private:
    int num;
    int den;
};

#endif

// Path: src/main.cpp
#include <iostream>
#include "Rational.h"

int main() {
    Rational r1(1, 2);
    Rational r2(1, 3);
    Rational r3 = r1 + r2;
    std::cout << r3 << std::endl;
    return 0;
}

Output

1/6

Conclusion

In this tutorial, we have learned how to overload operators in C++. We have also learned how to overload the following operators:

Arithmetic operators

Relational operators

Increment and decrement operators

Unary operators

Assignment operators

I hope you have enjoyed this tutorial. If you have any questions, please feel free to ask them in the comments section below.

Happy coding!

Related Posts

C++ Tutorial: How to overload the subscript operator

C++ Tutorial: How to overload the subscript operator

C++ Tutorial: How to overload the subscript operator

C++ Tutorial: How to overload the subscript operator

C++ Tutorial: How to overload the subscript operator



