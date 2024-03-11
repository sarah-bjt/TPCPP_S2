#include "fraction.hpp"
#include "utils.hpp"

#include <iostream>

// écriture des fractions
void Fraction::display() {
    std::cout << numerator << "/" << denominator;
}


// // ex1 opération (+, -, * , /)
// // +
// Fraction operator+(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator + f2.numerator * f1.denominator,
//         f1.denominator * f2.denominator
//     });
// }
// // -
// Fraction operator-(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator - f2.numerator * f1.denominator,
//         f1.denominator * f2.denominator
//     });
// }
// // *
// Fraction operator*(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.numerator,
//         f1.denominator * f2.denominator
//     });
// }
// // /
// Fraction operator/(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator,
//         f1.denominator * f2.numerator
//     });
// }


// ex2 affichage
std::ostream& operator<<(std::ostream& os, Fraction f) {
    return os << f.numerator<<"/"<<f.denominator;
}

// ex3 égalité (==, !=)
// ==
bool operator==(Fraction const& f1, Fraction const& f2) {
    Fraction simpF1 = simplify(f1);
    Fraction simpF2 = simplify(f2);
    return simpF1.numerator==simpF2.numerator && simpF1.denominator==simpF2.denominator;
}
// !=
bool operator!=(Fraction const& f1, Fraction const& f2) {
    return !(f1 == f2);
}

// ex4 comparaison (<, <=, >, >=)
// <
bool operator<(Fraction const& f1, Fraction const& f2) {
    return f1.numerator*f2.denominator < f2.numerator*f1.denominator;
}
//<=
bool operator<=(Fraction const& f1, Fraction const& f2) {
    return f1<f2 || f1==f2;
}
//>
bool operator>(Fraction const& f1, Fraction const& f2) {
    return !(f1<f2 );
}
//>=
bool operator>=(Fraction const& f1, Fraction const& f2) {
    return !(f1<f2 && f1!=f2 );
}

// ex5 opérations d'affectation 
// +=
Fraction& Fraction::operator+=(Fraction const& f){
        numerator = numerator * f.denominator + f.numerator * denominator;
        denominator = denominator * f.denominator;
        return simplify(*this);
}
//-=
Fraction& Fraction::operator-=(Fraction const& f) {

        numerator = numerator * f.denominator - f.numerator * denominator;
        denominator = denominator * f.denominator;
        return simplify(*this);
}
// *=
Fraction& Fraction::operator*=(Fraction const& f) {
        numerator *= f.numerator;
        denominator *= f.denominator;
        return simplify(*this);
}
// /=
Fraction& Fraction::operator/=(Fraction const& f) {
        numerator *= f.denominator;
        denominator *= f.numerator;
        return simplify(*this);
}
// réecriture (+, -, *, /)
// +
Fraction operator+(Fraction  f1, Fraction const& f2) {
    f1 += f2;
    return f1;
}
// -
Fraction operator-(Fraction f1, Fraction const& f2) {
    f1-=f2;
    return f1;
}
// *
Fraction operator*(Fraction f1, Fraction const& f2) {
    f1*=f2;
    return f1;
}
// /
Fraction operator/(Fraction f1, Fraction const& f2) {
    f1/=f2;
    return f1;
}

// ex6 convestion
Fraction::operator float() const{
    float floatingNumerator {static_cast<float>(numerator)};
    float floatingDenominator {static_cast<float>(denominator)};
    return floatingNumerator/floatingDenominator;
}

