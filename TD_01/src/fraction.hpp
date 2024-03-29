#pragma once
#include<iostream>

struct Fraction {
    unsigned int numerator;
    unsigned int denominator;
    void display();

    // ex5 opérations d'affections (+=, -=, *=, /=)
    // +=
    Fraction& operator+=(Fraction const& f);
    // -=
    Fraction& operator-=(Fraction const& f);
    // *=
    Fraction& operator*=(Fraction const& f);
    // /=
    Fraction& operator/=(Fraction const& f2);

    // // ex6 convertion
    operator float() const ;
    
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
