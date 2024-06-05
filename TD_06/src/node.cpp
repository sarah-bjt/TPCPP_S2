#include "node.hpp"
#include<algorithm>

// Exercice 1 ( Implémentation)

// q.1
Node* create_node(int value) {
    return new Node { value, nullptr, nullptr};
}

// q.2
bool Node::is_leaf() const { 
    return left == nullptr && right == nullptr;
}

//q.3
void Node::insert(int value) {
    if (value < this->value) {
        if (left == nullptr) {
            left = create_node(value);
        } 
        else {
            left->insert(value);
        }
    } 
    else {
        if (right == nullptr) {
            right = create_node(value);
        } else {
            right->insert(value);
        }
    }
}

//q.4
int Node::height() const {
    
    int left_height{0};
    int right_height{0};

    if (this->left != nullptr)
        left_height += 1 + this->left->height(); // Hauteur du sous-arbre gauche
    if (this->right != nullptr)
        right_height += 1 + this->right->height(); // Hauteur du sous-arbre droit
    if (this->is_leaf())
        return 1; // Une feuille a une hauteur de 1 par convention
    if (left_height > right_height)
        return left_height;
    return right_height;
}

//q.5
void Node::delete_childs(){
    if (left != nullptr){
        left->delete_childs();
        delete left;
        left = nullptr;
    }
    if (right != nullptr){
        right->delete_childs();
        delete right;
        right = nullptr;
    }
}

//q.6
void Node::display_infixe() const{
    if (left != nullptr){
        left -> display_infixe();
    }

    std::cout<<value<<" ";

    if (right != nullptr){
        right -> display_infixe();
    }
}

//q.7
std::vector<Node const*> Node::prefixe() const{

    std::vector<Node  const*> result {};
    result.push_back(this);

    if (left) {
        auto left_result = left->prefixe();
        result.insert(result.end(), left_result.begin(), left_result.end());
    }

    if (right) {
        auto right_result = right->prefixe();
        result.insert(result.end(), right_result.begin(), right_result.end());
    }

    return result;
}

//q.9
Node*& most_left(Node*& node){
    if ( node->left != nullptr)
        return most_left(node->left);
    return node;
}

//q.10
bool remove(Node*& node, int value){
    if (value == node->value && node->is_leaf()) {
        // On supprime le nœud courant
        delete node;
        // Comme on a une référence sur le pointeur du nœud courant, on le met à jour avec nullptr
        // Ainsi le parent du nœud courant aura un pointeur vers nullptr
        node = nullptr;
        // on retourne true car la suppression a été effectuée
        return true;
    }
    else if (value == node->value && !(node->is_leaf()) ){
        if (node->left == nullptr){
            Node* tempo {node};
            node = node->right;
            delete tempo;
            return true;
        }
        else if (node->right == nullptr){
            Node* tempo {node};
            node = node->left;
            delete tempo;
            return true;
        }
        else {
            Node*& most_left_node = most_left(node->right);
            node->value = most_left_node->value;
            delete most_left_node;
            most_left_node = nullptr;
            return true;
        }
    }
    else{return false;}
}

//q.11
void delete_tree(Node* node){
    if (node != nullptr) {
        delete_tree(node->left);
        delete_tree(node->right);
        delete node;
    }
}
