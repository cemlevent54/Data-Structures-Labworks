#pragma once
#include<iostream>
#include<queue>
using namespace std;
#include <string>

// Node structure for the tree
template <typename T>
struct Node {
    T value;
    Node<T>* left;
    Node<T>* right;

    // Constructor
    Node(T val);
};

template <typename T>
Node<T>::Node(T val) {
    value = val;
    left = nullptr;
    right = nullptr;
}