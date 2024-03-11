#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction f1 { 3, 4 };
    Fraction f2 { 1, 2 };

    std::cout << "f1 = ";
    std::cout<<f1;
    std::cout << " f2 = ";
    std::cout<<f2;
    std::cout << std::endl;

    // rappel
    std::cout<< "oui = ";
    std::cout<<true;
    std::cout<<std::endl;
    std::cout<< "non = ";
    std::cout<<false;
    std::cout<<std::endl;


// ex1 (opération), ex2 (affichage), ex5 (opérations d'affectation)

    // +
    std::cout << f1 <<" + "<< f2 <<"= ";
    std::cout<<(f1+f2);
    std::cout<<std::endl;
    // -
    std::cout << f1 <<" - "<<f2<<" = ";
    std::cout<<(f1-f2);
    std::cout<<std::endl;
    // *
    std::cout << f1 <<" x "<<f2<<" = ";
    std::cout<<(f1 * f2);
    std::cout<<std::endl;
    // /
    std::cout << "("<<f1<<") "<<"/"<<" ("<<f2<<")"<<" = ";
    std::cout<<(f1/f2);
    std::cout<<std::endl;


// ex3 (égalité)
    // ==
    std::cout<< "1/2 = 2/4 ? ";
    std::cout<<(Fraction{1, 2} == Fraction{2, 4});
    std::cout<<std::endl;
    // !=
    std::cout<< "3/4 != 2/4 ? ";
    std::cout<<(Fraction{3, 4} != Fraction{2, 4});
    std::cout<<std::endl;

// ex4 (comparaison)
    // <
    std::cout<< "3/4 < 2/4 ? ";
    std::cout<<(Fraction{3, 4} < Fraction{2, 4});
    std::cout<<std::endl;
    // <=
    std::cout<< "3/4 <= 2/4 ? ";
    std::cout<<(Fraction{3, 4} <= Fraction{2, 4});
    std::cout<<std::endl;
    // >
    std::cout<< "3/4 > 2/4 ? ";
    std::cout<<(Fraction{3, 4} > Fraction{2, 4});
    std::cout<<std::endl;
    // >=
    std::cout<< "3/4 >= 2/4 ? ";
    std::cout<<(Fraction{3, 4} > Fraction{2, 4});
    std::cout<<std::endl;

    // ex6 (convertion)
    std::cout<<f1 << " = ";
    std::cout<<static_cast<float>(f1);
    std::cout<<std::endl;

    return 0;
}