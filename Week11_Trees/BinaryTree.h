#pragma once
using namespace std;
#include <iostream>
#include <queue>
#include "Node.h"

// Binary Tree class
class BinaryTree {
private:
    Node* rootOption1;
    Node* rootOption2;
    void preorder(Node* node);
    void inorder(Node* node);
    void postorder(Node* node);
public:
    BinaryTree();
    void insertOption1(int value);
    void insertOption2(int value);
    void preorderOption1();
    void inorderOption1();
    void postorderOption1();
    void preorderOption2();
    void inorderOption2();
    void postorderOption2();
};

BinaryTree::BinaryTree() {
	rootOption1 = nullptr;
	rootOption2 = nullptr;
}

void BinaryTree::preorder(Node* node) {
	if (node == nullptr) return;
	cout << node->value << " ";
	preorder(node->left);
	preorder(node->right);
}

void BinaryTree::inorder(Node* node) {
	if (node == nullptr) return;
	inorder(node->left);
	cout << node->value << " ";
	inorder(node->right);
}

void BinaryTree::postorder(Node* node) {
	if (node == nullptr) return;
	postorder(node->left);
	postorder(node->right);
	cout << node->value << " ";
}

void BinaryTree::insertOption1(int value) {
    Node* newNode = new Node(value);
    if (rootOption1 == nullptr) {
        rootOption1 = newNode;
        return;
    }

    // Use a queue for level-order insertion
    queue<Node*> q;
    q.push(rootOption1);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (current->left == nullptr) {
            current->left = newNode;
            break;
        }
        else {
            q.push(current->left);
        }

        if (current->right == nullptr) {
            current->right = newNode;
            break;
        }
        else {
            q.push(current->right);
        }
    }
}

void BinaryTree::insertOption2(int value) {
    Node* newNode = new Node(value);
    if (rootOption2 == nullptr) {
        rootOption2 = newNode; // Ýlk düðüm kök olur
        return;
    }

    // Use a queue for level-order insertion
    queue<Node*> q;
    q.push(rootOption2);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        // Sað çocuðu boþsa, buraya ekle
        if (current->right == nullptr) {
            current->right = newNode;
            break;
        }
        // Sol çocuðu boþsa, buraya ekle
        else if (current->left == nullptr) {
            current->left = newNode;
            break;
        }

        // Eðer her iki çocuk da doluysa sýradaki düðüme geç
        q.push(current->right); // Önce sað çocuða ilerle
        q.push(current->left);
    }
}

void BinaryTree::preorderOption1() {
	preorder(rootOption1);
    cout << endl;
}

void BinaryTree::inorderOption1() {
	inorder(rootOption1);
	cout << endl;
}

void BinaryTree::postorderOption1() {
	postorder(rootOption1);
	cout << endl;
}

void BinaryTree::preorderOption2() {
	preorder(rootOption2);
	cout << endl;
}

void BinaryTree::inorderOption2() {
	inorder(rootOption2);
	cout << endl;
}

void BinaryTree::postorderOption2() {
	postorder(rootOption2);
	cout << endl;
}