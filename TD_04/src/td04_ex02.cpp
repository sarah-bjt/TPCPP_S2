#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <list>

// Exercice 2 - string

//  savoir si un caractère est un espace:
auto const is_space = [](char letter){ return letter == ' '; };

// q.1 
int nbrLettre1erMot(std::string const& phrase){
    auto i_max {std::find(phrase.begin(), phrase.end(),' ')};
    auto nbr {std::distance(phrase.begin(),i_max)};
    return static_cast<int>(nbr);
}

// q.2
std::vector<std::string> split_string(std::string const& str){
    std::vector<std::string> tableau;
    int lastStop{0};
    for ( int i{0}; i<str.end(); i++){
        if (is_space(i)){

        }
    }
    

}



int main(){
    std::string phrase {"coder une autre facon"};
    //q.1
    std::cout<<"Le nombre de lettre dans le premier mot de "<< phrase << " est"<< nbrLettre1erMot(phrase)<<std::endl;
}

