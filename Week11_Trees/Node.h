#pragma once
#include<iostream>
#include<queue>
using namespace std;

// Node structure for the tree
struct Node {
	int value;
	Node* left;
	Node* right;

	Node(int val);
	
};

Node::Node(int val) {
	value = val;
	left = nullptr;
	right = nullptr;
}