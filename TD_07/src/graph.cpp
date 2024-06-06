#include <iostream>
#include "graph.hpp"
#include <queue>
#include <stack>
#include <unordered_set>


// exo 1
//q.1
void Graph::WeightedGraph::add_vertex(int const id) {
    if (this->adjacency_list.find(id) == this->adjacency_list.end()) {
        this->adjacency_list[id] = {};
    }
}

//q.2
void Graph::WeightedGraph::add_directed_edge(int const from, int const to, float weight){
    this->add_vertex(from);
    this->add_vertex(to);
    adjacency_list[from].push_back({to, weight});
}

//q.3
void Graph::WeightedGraph::add_undirected_edge(int const from, int const to, float const weight){
    WeightedGraph::add_directed_edge(from, to, weight);
    WeightedGraph::add_directed_edge(to, from, weight);
}
        
//q.4
Graph::WeightedGraph adjacency_list_from_adjacency_matrix(const std::vector<std::vector<float>>& adjacency_matrix) {
    Graph::WeightedGraph graph;
    for (unsigned int i {0}; i < adjacency_matrix.size(); ++i) {
        for (unsigned int j{0}; j < adjacency_matrix.size(); ++j) {
            if (adjacency_matrix[i][j] != 0) {
                graph.add_directed_edge(i, j, adjacency_matrix[i][j]);
            }
        }
    }
    return graph;
}

//q.5
// Afficher le graphe
void Graph::WeightedGraph::print() const {
    for (const auto& [sommet, arete] : adjacency_list) {
        std::cout << "Sommet " << sommet << " a pour aretes: "<<std::endl;
        for (const auto& arete : arete) {
            std::cout << "  -> " << arete.to << " (poids " << arete.weight << ")"<<std::endl;
        }
    }
}



//exo2
//q.1
void Graph::WeightedGraph::print_DFS(int const start) const{
    std::unordered_set<int> deja_visite;
    std::stack<int> a_visiter; 

    while (!a_visiter.empty()) {
        int sommet = a_visiter.top();
        a_visiter.pop();

        if (deja_visite.find(sommet) == deja_visite.end()) {
            std::cout << sommet << " ";
            deja_visite.insert(sommet);

            for (const auto& arete : adjacency_list.at(sommet)) {
                if (deja_visite.find(arete.to) == deja_visite.end()) {
                    a_visiter.push(arete.to);
                }
            }
        }
    }
    std::cout << std::endl;
}

//q.2
void Graph::WeightedGraph::print_BFS(int const start) const{
    std::unordered_set<int> deja_visite;
    std::queue<int> a_visiter;
    a_visiter.push(start);

    while (!a_visiter.empty()) {
        int sommet = a_visiter.front();
        a_visiter.pop();

        if (deja_visite.find(sommet) == deja_visite.end()) {
            std::cout << sommet << " ";
            deja_visite.insert(sommet);

            for (const auto& arete : adjacency_list.at(sommet)) {
                if (deja_visite.find(arete.to) == deja_visite.end()) {
                    a_visiter.push(arete.to);
                }
            }
        }
    }
    std::cout << std::endl;
}
