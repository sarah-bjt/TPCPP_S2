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
std::vector<std::string> split_string(std::string const& str) {
    std::vector<std::string> tableau;
    auto start = str.begin();
    auto last_stop = std::find(start, str.end(), ' ');

    while (last_stop != str.end()) {
        std::string new_word(start, last_stop);
        tableau.push_back(new_word);
        start = last_stop + 1;
        last_stop = std::find(start, str.end(), ' ');
    }

    if (start != str.end()) {
        tableau.push_back(std::string(start, str.end()));
    }
    return tableau;
}

int main(){
    std::string phrase {"coder une autre facon"};
    //q.1
    std::cout<<"Le nombre de lettre dans le premier mot de \""<< phrase << "\" est "<< nbrLettre1erMot(phrase)<<std::endl;
    //q.2
    std::vector<std::string> mots {split_string(phrase)};
    for(auto i {mots.begin()}; i<mots.end(); i++){
        std::cout << *i << std::endl;
    }
}

