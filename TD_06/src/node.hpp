#pragma once
#include <iostream>
#include <vector>

// Ex1
struct Node{
    int value;
    Node* left { nullptr };
    Node* right { nullptr };

    bool is_leaf() const; //q.2
    void insert(int value); //q.3
    int height() const; //q.4
    void delete_childs(); //q.5
    void display_infixe() const; //q.6
    std::vector<Node const*> prefixe() const; //q.7
};


Node* create_node(int value); //q.1
Node*& most_left(Node*& node); //q.9
bool remove(Node*& node, int value); //q.10
void delete_tree(Node* node); //q.11

