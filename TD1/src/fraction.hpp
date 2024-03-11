#pragma once
#include<iostream>

struct Fraction {
    unsigned int numerator;
    unsigned int denominator;
    void display();

    // ex5 opérations d'affections (+=, -=, *=, /=)
    // +=
    Fraction& operator+=(Fraction const& f2) {
        numerator = numerator * f2.denominator + f2.numerator * denominator;
        denominator = denominator * f2.denominator;
        return *this;
    }
    // -=
    Fraction& operator-=(Fraction const& f2) {

        numerator = numerator * f2.denominator - f2.numerator * denominator;
        denominator = denominator * f2.denominator;
        return *this;
    }
    // *=
    Fraction& operator*=(Fraction const& f2) {
        numerator *= f2.numerator;
        denominator *= f2.denominator;
        return *this;
    }
    // /=
    Fraction& operator/=(Fraction const& f2) {
        numerator *= f2.denominator;
        denominator *= f2.numerator;
        return *this;
    }

};

// ex1
Fraction operator+(Fraction  f1, Fraction const& f2);
Fraction operator-(Fraction f1, Fraction const& f2);
Fraction operator*(Fraction  f1, Fraction const& f2);
Fraction operator/(Fraction f1, Fraction const& f2);
// ex2
std::ostream& operator<<(std::ostream& os, Fraction f);
// ex3
bool operator==(Fraction const& f1, Fraction const& f2);
bool operator!=(Fraction const& f1, Fraction const& f2);
// ex4
bool operator<(Fraction const& f1, Fraction const& f2);
bool operator<=(Fraction const& f1, Fraction const& f2);
bool operator>(Fraction const& f1, Fraction const& f2);
bool operator>=(Fraction const& f1, Fraction const& f2);