#include <iostream>
#include <queue>
using namespace std;

// Node structure for the tree
#include "Node.h"

// Binary Tree class 
#include "BinaryTree.h"

// Binary Search Tree class
#include "BSTTree.h"


void Q1() {
    BinaryTree tree;
    int values[] = { 4, 6, 12, 45, 7, 1 };

    for (int value : values) {
        tree.insertOption1(value);
    }

    cout << "Binary Tree Option 1:" << endl;
    cout << "Preorder traversal: ";
    tree.preorderOption1();

    cout << "Inorder traversal: ";
    tree.inorderOption1();

    cout << "Postorder traversal: ";
    tree.postorderOption1();
}

void Q2() {
    BinaryTree tree;
    int values[] = { 4, 6, 12, 45, 7, 1 };

    for (int value : values) {
        tree.insertOption2(value);
    }

    cout << "Binary Tree Option 2:" << endl;
    cout << "Preorder traversal: ";
    tree.preorderOption2();

    cout << "Inorder traversal: ";
    tree.inorderOption2();

    cout << "Postorder traversal: ";
    tree.postorderOption2();
}

void Q3() {
    BSTTree bsttree;

    // Build tree from pre-order sequence
    int preorder[] = { 10, 5, 1, 7, 40, 50 };
    int preorderSize = sizeof(preorder) / sizeof(preorder[0]);
    bsttree.buildTreeFromPreOrder(preorder, preorderSize);
    std::cout << "Tree built from pre-order\n";
    bsttree.inOrder();
    bsttree.preOrder();

    // Build tree from BFS sequence
    int bfs[] = { 7, 4, 12, 3, 6, 8, 1, 5, 10 };
    int bfsSize = sizeof(bfs) / sizeof(bfs[0]);
    bsttree.buildTreeFromBFS(bfs, bfsSize);
    std::cout << "Tree built from BFS:\n";
    bsttree.inOrder();
    bsttree.preOrder();
    bsttree.bfs();
}

int main() {
    cout << "Week 11 - Trees" << endl;
#if 1
    cout << "Question 1: " << endl;
    Q1();
#endif
#if 1
	cout << "Question 2: " << endl;
    Q2();
#endif
#if 1
	cout << "Question 3: " << endl;
    Q3();
#endif



    return 0;
}
