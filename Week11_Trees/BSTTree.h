#pragma once
#include<iostream>
#include<queue>
using namespace std;

// Node structure for the tree
#include "Node.h"

// Binary Tree class
class BSTTree {
private:
	Node* root;
	Node* insert(Node* node, int val);
	Node* buildFromPreOrder(int preorder[], int& index, int min, int max, int n);
	Node* buildFromBFS(int bfs[], int n);
	void inOrder(Node* node);
	void preOrder(Node* node);
	void postOrder(Node* node);
	void bfs(Node* node);
public:
	BSTTree();
	void insert(int value);
	void buildTreeFromPreOrder(int preorder[], int n);
	void buildTreeFromBFS(int bfs[], int n);
	void inOrder();
	void preOrder();
	void postOrder();
	void bfs();
};

BSTTree::BSTTree() {
	root = nullptr;
}

Node* BSTTree::insert(Node* node, int val) {
	if (node == nullptr) {
		return new Node(val);
	}
	if (val < node->value) {
		node->left = insert(node->left, val);
	}
	else {
		node->right = insert(node->right, val);
	}
	return node;
}

Node* BSTTree::buildFromPreOrder(int preorder[], int& index, int min, int max, int n) {
	if (index >= n) return nullptr;

	int val = preorder[index];
	if (val < min || val > max) return nullptr;

	Node* node = new Node(val);
	index++;

	node->left = buildFromPreOrder(preorder, index, min, val - 1, n);
	node->right = buildFromPreOrder(preorder, index, val + 1, max, n);

	return node;
}

Node* BSTTree::buildFromBFS(int bfs[], int n) {
	if (n == 0) return nullptr;

	Node* root = new Node(bfs[0]);
	queue<pair<Node*, pair<int, int>>> q; // Node ve min/max sýnýrlarý
	q.push({ root, {INT_MIN, INT_MAX} });

	int i = 1;
	while (!q.empty() && i < n) {
		auto current = q.front();
		q.pop();

		Node* parent = current.first;
		int min = current.second.first;
		int max = current.second.second;

		// Sol çocuk için kontrol
		if (i < n && bfs[i] > min && bfs[i] < parent->value) {
			parent->left = new Node(bfs[i]);
			q.push({ parent->left, {min, parent->value} });
			i++;
		}

		// Sað çocuk için kontrol
		if (i < n && bfs[i] > parent->value && bfs[i] < max) {
			parent->right = new Node(bfs[i]);
			q.push({ parent->right, {parent->value, max} });
			i++;
		}
	}

	return root;
}

void BSTTree::inOrder(Node* node) {
	if (node == nullptr) return;
	inOrder(node->left);
	cout << node->value << " ";
	inOrder(node->right);
}

void BSTTree::preOrder(Node* node) {
	if (node == nullptr) return;
	cout << node->value << " ";
	preOrder(node->left);
	preOrder(node->right);
}

void BSTTree::postOrder(Node* node) {
	if (node == nullptr) return;
	postOrder(node->left);
	postOrder(node->right);
	cout << node->value << " ";
}

void BSTTree::bfs(Node* node) {
	if (node == nullptr) return;

	queue<Node*> q;
	q.push(node);

	while (!q.empty()) {
		Node* current = q.front();
		q.pop();

		cout << current->value << " ";

		if (current->left != nullptr) q.push(current->left);
		if (current->right != nullptr) q.push(current->right);
	}
}

void BSTTree::insert(int value) {
	root = insert(root, value);
}

void BSTTree::inOrder() {
	cout << "In-order Traversal: ";
	inOrder(root);
	cout << endl;
}

void BSTTree::preOrder() {
	cout << "Pre-order Traversal: ";
	preOrder(root);
	cout << endl;
}

void BSTTree::postOrder() {
	cout << "Post-order Traversal: ";
	postOrder(root);
	cout << endl;
}

void BSTTree::bfs() {
	cout << "Breadth-first Traversal: ";
	bfs(root);
	cout << endl;
}

void BSTTree::buildTreeFromPreOrder(int preorder[], int n) {
	int index = 0;
	root = buildFromPreOrder(preorder, index, INT_MIN, INT_MAX, n);
}

void BSTTree::buildTreeFromBFS(int bfs[], int n) {
	root = buildFromBFS(bfs, n);
}