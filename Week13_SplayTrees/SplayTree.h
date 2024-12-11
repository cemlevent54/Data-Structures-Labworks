#pragma once
#include <iostream>
using namespace std;
#include "SplayNode.h"

class SplayTree {
private:
    SplayNode* root;

    SplayNode* rightRotate(SplayNode* x);
    SplayNode* leftRotate(SplayNode* x);
    SplayNode* splay(SplayNode* root, int key);
    SplayNode* insert(SplayNode* root, int key);
    void preOrder(SplayNode* root);
    void inOrder(SplayNode* root);
    void postOrder(SplayNode* root);
    SplayNode* bstSearch(SplayNode* root, int key);
    SplayNode* subtree_Min(SplayNode* subRoot);
    SplayNode* subtree_Max(SplayNode* subRoot);
    void printTree(SplayNode* root, int space = 0, int COUNT = 10);

public:
    SplayTree() : root(nullptr) {}
    void insert(int key);
    void preOrder();
    void inOrder();
    void postOrder();
    SplayNode* getRoot() { return root; }
    SplayNode* bstSearch(int key) { return bstSearch(root, key); }
    SplayNode* subtree_Min();
    SplayNode* subtree_Max();
    void printTree();
};

SplayNode* SplayTree::rightRotate(SplayNode* x) {
    SplayNode* y = x->left; // left child
    x->left = y->right; // move right subtree of y to left of x
    y->right = x; // move x to right of y
    return y; // y is the new root
}

SplayNode* SplayTree::leftRotate(SplayNode* x) {
    SplayNode* y = x->right; // right child
    x->right = y->left; // move left subtree of y to right of x
    y->left = x; // move x to left of y
    return y; // y is the new root
}

SplayNode* SplayTree::splay(SplayNode* root, int key) {
    if (!root || root->key == key) {
        return root;
    }

    // Key lies in left subtree
    if (key < root->key) {
        if (!root->left) return root;

        // Zig-Zig (Left Left)
        if (key < root->left->key) {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        }
        // Zig-Zag (Left Right)
        else if (key > root->left->key) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right) {
                root->left = leftRotate(root->left);
            }
        }

        return (root->left) ? rightRotate(root) : root;
    }

    else {
        if (!root->right) return root;

        // Zag-Zig (Right Left)
        if (key < root->right->key) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left) {
                root->right = rightRotate(root->right);
            }
        }

        // Zag-Zag (Right Right)
        else if (key > root->right->key) {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }

        return (root->right) ? leftRotate(root) : root;
    }
}

SplayNode* SplayTree::insert(SplayNode* root, int key) {
    if (!root) return new SplayNode(key);

    root = splay(root, key);

    if (root->key == key) return root;

    SplayNode* newNode = new SplayNode(key);
    if (key < root->key) {
        newNode->right = root;
        newNode->left = root->left;
        root->left = nullptr;
    }
    else {
        newNode->left = root;
        newNode->right = root->right;
        root->right = nullptr;
    }
    return newNode;
}

void SplayTree::preOrder(SplayNode* root) {
    if (!root) return;
    cout << root->key << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void SplayTree::inOrder(SplayNode* root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->key << " ";
    inOrder(root->right);
}

void SplayTree::postOrder(SplayNode* root) {
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->key << " ";
}

void SplayTree::insert(int key) {
    root = insert(root, key);
}

void SplayTree::preOrder() {
    cout << "PreOrder: ";
    preOrder(root);
    cout << endl;
}

void SplayTree::inOrder() {
    cout << "InOrder: ";
    inOrder(root);
    cout << endl;
}

void SplayTree::postOrder() {
    cout << "PostOrder: ";
    postOrder(root);
    cout << endl;
}

SplayNode* SplayTree::bstSearch(SplayNode* root, int key) {
    if (!root || root->key == key) return root;

    if (key < root->key) {
        return bstSearch(root->left, key);
    }
    else {
        return bstSearch(root->right, key);
    }
}

SplayNode* SplayTree::subtree_Min(SplayNode* subRoot) {
    if (!subRoot) return nullptr;

    SplayNode* current = subRoot;
    while (current->left) {
        current = current->left;
    }
    return current;
}

SplayNode* SplayTree::subtree_Max(SplayNode* subRoot) {
    if (!subRoot) return nullptr;

    SplayNode* current = subRoot;
    while (current->right) {
        current = current->right;
    }
    return current;
}

SplayNode* SplayTree::subtree_Min() {
    return subtree_Min(root);
}

SplayNode* SplayTree::subtree_Max() {
    return subtree_Max(root);
}

void SplayTree::printTree(SplayNode* root, int space, int COUNT) {
    if (!root) return;
    space += COUNT;
    printTree(root->right, space, COUNT);
    cout << endl;
    for (int i = COUNT; i < space; i++) cout << " ";
    cout << root->key << "\n";
    printTree(root->left, space, COUNT);
}

void SplayTree::printTree() { printTree(root, 0, 10); }