#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <list>

// Exercice 1 - vectir and algorithm

int main()
{

    std::srand(std::time(nullptr));

    // q.1 nombres entiers aléatoires compris entre 0 et 100.
    std::vector<int> vec(10);
    for (int i = 0; i < 10; i++)
    {
        vec[i] = rand() % 100;
    }

    // q.5 utiliser std::sort
    std::sort(vec.begin(),vec.end());


    // q.2 afficher les valeurs du vecteur avec begin, end, for
    for (auto iterateur = vec.begin(); iterateur != vec.end(); iterateur++)
    {
        std::cout << *iterateur << std::endl;
    };

    // q.3 utiliser std::find pour voir si un nbr est dans le vec
    int nbr_utilisateur {0};
    std::cout<< "donner un nombre"<<std::endl;
    std::cin>>nbr_utilisateur;

    auto nbr_present {std::find(vec.begin(), vec.end(),nbr_utilisateur)};

    // q.4 utiliser std::count
    int combien_de_fois {std::count(vec.begin(), vec.end(),nbr_utilisateur)};

    if ( nbr_present != vec.end() ){
        std::cout << "votre nombre est dans la liste "<< combien_de_fois<<" fois."<< std::endl;
    }
    else {
        std::cout << "votre nombre n'est pas dans la liste"<< std::endl;
    };

    // q.6 utiliser std::accumulate
    int somme { std::accumulate(vec.begin(), vec.end(), 0,[](int acc, int current_ele){return acc+current_ele;})};
    std::cout<< "la somme de tous les vecteurs est egale a "<<somme<< std::endl;

    return 0;
}