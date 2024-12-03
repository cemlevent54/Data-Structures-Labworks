#pragma once
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <sstream>
#include "BSTCityNode.h"
using namespace std;

class BinarySearchTreeCity {
private:
    BSTCityNode* root;

    // Private helper methods
    BSTCityNode* insert(BSTCityNode* node, pair<string, int> val);
    void inOrderTraversal(BSTCityNode* node, int& count, int totalNodes);
    void preOrderTraversal(BSTCityNode* node, int& count, int totalNodes);
    void postOrderTraversal(BSTCityNode* node, int& count, int totalNodes);
    void bfsTraversal(BSTCityNode* node);
    int countNodes(BSTCityNode* node);

    // Subtree checking with string conversion
    void treeToString(BSTCityNode* node, string& str);
    bool isSubtreeWithStrings(BSTCityNode* mainTree, BSTCityNode* subTree);

    // Subtree checking with structural comparison
    bool areIdentical(BSTCityNode* tree1, BSTCityNode* tree2);
    bool isSubtree(BSTCityNode* mainTree, BSTCityNode* subTree);

public:
    // Constructor
    BinarySearchTreeCity();

    // Public methods
    void insert(pair<string, int> value);
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
    void bfsTraversal();
    bool isSubtree(BinarySearchTreeCity& subtree);

    // Getter for root
    BSTCityNode* getRoot();
};
#include "BinarySearchTreeCity.h"

// Constructor
BinarySearchTreeCity::BinarySearchTreeCity() {
    root = nullptr;
}

// Getter for root
BSTCityNode* BinarySearchTreeCity::getRoot() {
    return root;
}

// Public method: Insert a value
void BinarySearchTreeCity::insert(pair<string, int> value) {
    root = insert(root, value);
}

// Private recursive insert method
BSTCityNode* BinarySearchTreeCity::insert(BSTCityNode* node, pair<string, int> val) {
    if (node == nullptr) {
        return new BSTCityNode(val);
    }
    if (val.second < node->getValue().second) {
        node->setLeft(insert(node->getLeft(), val));
    }
    else {
        node->setRight(insert(node->getRight(), val));
    }
    return node;
}

// Private method to count nodes
int BinarySearchTreeCity::countNodes(BSTCityNode* node) {
    if (node == nullptr) return 0;
    return 1 + countNodes(node->getLeft()) + countNodes(node->getRight());
}

// Public method for in-order traversal
void BinarySearchTreeCity::inOrderTraversal() {
    int totalNodes = countNodes(root);
    int count = 0;
    cout << "In-order Traversal: ";
    inOrderTraversal(root, count, totalNodes);
    cout << endl;
}

// Private in-order traversal
void BinarySearchTreeCity::inOrderTraversal(BSTCityNode* node, int& count, int totalNodes) {
    if (node == nullptr) return;
    inOrderTraversal(node->getLeft(), count, totalNodes);
    cout << node->getValue().first;
    if (++count < totalNodes) {
        cout << " -> ";
    }
    inOrderTraversal(node->getRight(), count, totalNodes);
}

// Public method for pre-order traversal
void BinarySearchTreeCity::preOrderTraversal() {
    int totalNodes = countNodes(root);
    int count = 0;
    cout << "Pre-order Traversal: ";
    preOrderTraversal(root, count, totalNodes);
    cout << endl;
}

// Private pre-order traversal
void BinarySearchTreeCity::preOrderTraversal(BSTCityNode* node, int& count, int totalNodes) {
    if (node == nullptr) return;
    cout << node->getValue().first;
    if (++count < totalNodes) {
        cout << " -> ";
    }
    preOrderTraversal(node->getLeft(), count, totalNodes);
    preOrderTraversal(node->getRight(), count, totalNodes);
}

// Public method for post-order traversal
void BinarySearchTreeCity::postOrderTraversal() {
    int totalNodes = countNodes(root);
    int count = 0;
    cout << "Post-order Traversal: ";
    postOrderTraversal(root, count, totalNodes);
    cout << endl;
}

// Private post-order traversal
void BinarySearchTreeCity::postOrderTraversal(BSTCityNode* node, int& count, int totalNodes) {
    if (node == nullptr) return;
    postOrderTraversal(node->getLeft(), count, totalNodes);
    postOrderTraversal(node->getRight(), count, totalNodes);
    cout << node->getValue().first;
    if (++count < totalNodes) {
        cout << " -> ";
    }
}

// Public method for BFS traversal
void BinarySearchTreeCity::bfsTraversal() {
    cout << "Breadth-first Traversal: ";
    bfsTraversal(root);
    cout << endl;
}

// Private BFS traversal
void BinarySearchTreeCity::bfsTraversal(BSTCityNode* node) {
    if (node == nullptr) return;

    queue<BSTCityNode*> q;
    q.push(node);
    int totalNodes = countNodes(node);
    int count = 0;

    while (!q.empty()) {
        BSTCityNode* current = q.front();
        q.pop();
        cout << current->getValue().first;
        if (++count < totalNodes) {
            cout << " -> ";
        }
        if (current->getLeft() != nullptr) q.push(current->getLeft());
        if (current->getRight() != nullptr) q.push(current->getRight());
    }
}

// Convert tree to string (pre-order traversal)
void BinarySearchTreeCity::treeToString(BSTCityNode* node, string& str) {
    if (node == nullptr) {
        str += "X "; // Represent null nodes
        return;
    }
    str += "(" + node->getValue().first + "," + to_string(node->getValue().second) + ") ";
    treeToString(node->getLeft(), str);
    treeToString(node->getRight(), str);
}

// Check if two trees are identical
bool BinarySearchTreeCity::areIdentical(BSTCityNode* tree1, BSTCityNode* tree2) {
    if (tree1 == nullptr && tree2 == nullptr) return true;
    if (tree1 == nullptr || tree2 == nullptr) return false;

    return (tree1->getValue() == tree2->getValue() &&
        areIdentical(tree1->getLeft(), tree2->getLeft()) &&
        areIdentical(tree1->getRight(), tree2->getRight()));
}

// Check if one tree is a subtree of another
bool BinarySearchTreeCity::isSubtree(BSTCityNode* mainTree, BSTCityNode* subTree) {
    if (subTree == nullptr) return true;
    if (mainTree == nullptr) return false;

    if (areIdentical(mainTree, subTree)) return true;

    return isSubtree(mainTree->getLeft(), subTree) || isSubtree(mainTree->getRight(), subTree);
}

// Public isSubtree method
bool BinarySearchTreeCity::isSubtree(BinarySearchTreeCity& subtree) {
    return isSubtree(root, subtree.getRoot());
}
