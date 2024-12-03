#pragma once
#include <iostream>
#include <queue>
#include <limits>
using namespace std;

#include "BSTNode.h"

// Generic Binary Search Tree (BST) class
template <typename T>
class BSTTree {
private:
    Node<T>* root;

    Node<T>* insert(Node<T>* node, T val);
    void inOrder(Node<T>* node);
    void preOrder(Node<T>* node);
    void postOrder(Node<T>* node);
    void bfs(Node<T>* node);

public:
    BSTTree();
    void insert(T value);
    void inOrder();
    void preOrder();
    void postOrder();
    void bfs();
};

// Constructor
template <typename T>
BSTTree<T>::BSTTree() {
    root = nullptr;
}

// Insert a value into the tree
template <typename T>
Node<T>* BSTTree<T>::insert(Node<T>* node, T val) {
    if (node == nullptr) {
        return new Node<T>(val);
    }
    if (val < node->value) {
        node->left = insert(node->left, val);
    }
    else {
        node->right = insert(node->right, val);
    }
    return node;
}

// Public insert function
template <typename T>
void BSTTree<T>::insert(T value) {
    root = insert(root, value);
}

// In-order traversal (left, root, right)
template <typename T>
void BSTTree<T>::inOrder(Node<T>* node) {
    if (node == nullptr) return;
    inOrder(node->left);
    cout << node->value << " ";
    inOrder(node->right);
}

template <typename T>
void BSTTree<T>::inOrder() {
    cout << "In-order Traversal: ";
    inOrder(root);
    cout << endl;
}

// Pre-order traversal (root, left, right)
template <typename T>
void BSTTree<T>::preOrder(Node<T>* node) {
    if (node == nullptr) return;
    cout << node->value << " ";
    preOrder(node->left);
    preOrder(node->right);
}

template <typename T>
void BSTTree<T>::preOrder() {
    cout << "Pre-order Traversal: ";
    preOrder(root);
    cout << endl;
}

// Post-order traversal (left, right, root)
template <typename T>
void BSTTree<T>::postOrder(Node<T>* node) {
    if (node == nullptr) return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->value << " ";
}

template <typename T>
void BSTTree<T>::postOrder() {
    cout << "Post-order Traversal: ";
    postOrder(root);
    cout << endl;
}

// Breadth-first traversal (BFS)
template <typename T>
void BSTTree<T>::bfs(Node<T>* node) {
    if (node == nullptr) return;

    queue<Node<T>*> q;
    q.push(node);

    while (!q.empty()) {
        Node<T>* current = q.front();
        q.pop();

        cout << current->value << " ";

        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
    }
}

template <typename T>
void BSTTree<T>::bfs() {
    cout << "Breadth-first Traversal: ";
    bfs(root);
    cout << endl;
}
