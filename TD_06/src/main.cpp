#include<node.hpp>

int main() {
    Node* root = create_node(5);
    std::vector<int> values = {3, 7, 2, 4, 6, 8, 1, 9, 0};

    for (int value : values) {
        root->insert(value);
    }

    std::cout << "Valeurs dans l'ordre infixe : ";
    root->display_infixe();
    std::cout << std::endl;

    std::vector<const Node*> nodes_prefixe = root->prefixe();
    int sum = 0;
    for (const Node* node : nodes_prefixe) {
        sum += node->value;
    }
    std::cout << "Somme des valeurs des noeuds (prefixe) : " << sum << std::endl;

    int height = root->height();
    std::cout << "Hauteur de l'arbre : " << height << std::endl;
    
    delete_tree(root);

    return 0;
}