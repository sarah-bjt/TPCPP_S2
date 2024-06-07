#include <iostream>
#include <vector>
#include <array>
#include "graph.hpp"




int main(){
    // matrice d'ajacence :
    const std::vector<std::vector<float>>& adjacency_matrix {
        {0,1,0,0,2},
        {1,0,2,4,0},
        {0,2,0,1,0},
        {0,4,1,0,6},
        {2,0,0,6,0}
    };

    // graphe avec la matrice
    Graph::WeightedGraph graphe_matrice { adjacency_list_from_adjacency_matrix(adjacency_matrix)};

    // graphe avec add_vertex et add_edge
    Graph::WeightedGraph graphe_add;
    graphe_add.add_undirected_edge(0,1);
    graphe_add.add_undirected_edge(0,4,2);
    graphe_add.add_undirected_edge(1,2,2);
    graphe_add.add_undirected_edge(1,3,4);
    graphe_add.add_undirected_edge(2,3);
    graphe_add.add_undirected_edge(3,4,6);

    std::cout << "Graphe de la matrice d'adjacence"<<std::endl;
    graphe_matrice.print();
    std::cout << "Graphe fait à la mano"<<std::endl;
    graphe_add.print();

    // Comparer les deux graphes
    if (graphe_matrice == graphe_add) {
        std::cout << "Les graphes sont egaux"<<std::endl;
    } else {
        std::cout << "Les graphes sont differents"<<std::endl;
    }

    return 0;
}


