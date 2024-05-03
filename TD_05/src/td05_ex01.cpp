#include <iostream>
#include <string>

// Exercice 1 - fonction de hachage -------------------------------------------------------------------
// 1 ) folding hash
size_t folding_string_hash(std::string const& s, size_t max){
    size_t hash {0};
    for ( unsigned int i {0} ; i < s.size(); i++){
        hash += s[i];
    }
    return hash%max;
}

// 2) folding order hash
size_t folding_string_ordered_hash(std::string const& s, size_t max){
    size_t hash {0};
    for ( unsigned int i {0} ; i < s.size(); i++){
        hash += s[i] * i ;
    }
    return hash%max;
}

// 3) polynomial rolling hash
size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m){
    size_t hash {0};
    for ( unsigned int i {0} ; i < s.size(); i++){
        int power {1};
        for ( unsigned int j {1}; j < i ; j++){
            power *= p;
        }
        hash += (s[i] * i * p )%m;
    }
    return hash;
}

int main(){
    std::string chaine1 {"yolo"};
    std::string chaine2 {"oloy"};

// exo1
    std::cout<< "le hash de "<< chaine1 << " pour le folding string est : " << folding_string_hash(chaine1, 1024) << std::endl;

    std::cout<< "le hash de "<< chaine1 << " pour le folding string avec un ordre est : " << folding_string_ordered_hash(chaine1, 1024) << std::endl;
    std::cout<< "le hash de "<< chaine2 << " pour le folding string avec un ordre est : " << folding_string_ordered_hash(chaine2, 1024) << std::endl;

    std::cout<< "le hash de "<< chaine1 << " pour le polynomial est : " << polynomial_rolling_hash(chaine1,2, 1024) << std::endl;

}