#pragma once
#include <iostream>
using namespace std;

// AVL Tree Node
struct AVLNode {
    string key;
    int frequency;
    AVLNode* left, * right;
    int height;

    AVLNode(string k) : key(k), frequency(1), left(nullptr), right(nullptr), height(1) {}
};