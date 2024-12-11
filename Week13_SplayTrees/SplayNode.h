#pragma once
#include <iostream>
using namespace std;

class SplayNode {
public:
	int key;
	SplayNode* left;
	SplayNode* right;

	SplayNode(int data) : key(data), left(nullptr), right(nullptr) {}
};