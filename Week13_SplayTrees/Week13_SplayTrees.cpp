#include <iostream>
using namespace std;
#include "SplayTree.h"

int main()
{
    SplayTree tree;
    SplayNode* control;

    tree.insert(100);
    control = tree.getRoot();
    cout << "Root: " << control->key << endl;
    cout << "Splay Tree:" << endl;
    tree.printTree();
    tree.insert(50);
    control = tree.getRoot();
    cout << "Root: " << control->key << endl;
    cout << "Splay Tree:" << endl;
    tree.printTree();
    tree.insert(200);
    control = tree.getRoot();
    cout << "Root: " << control->key << endl;
    cout << "Splay Tree:" << endl;
    tree.printTree();
    tree.insert(40);
    control = tree.getRoot();
    cout << "Root: " << control->key << endl;
    cout << "Splay Tree:" << endl;
    tree.printTree();
    tree.insert(60);
    control = tree.getRoot();
    cout << "Root: " << control->key << endl;
    cout << "Splay Tree:" << endl;
    tree.printTree();
    tree.bstSearch(40);
    cout << "Splay Tree:" << endl;
    tree.printTree();
    tree.insert(150);
    cout << "Splay Tree:" << endl;
    tree.printTree();


    // Traversal 
    tree.preOrder();
    tree.inOrder();
    tree.postOrder();
    control = tree.getRoot();
    cout << "Root: " << control->key << endl;


    // Ağacı görsel olarak yazdır
    cout << "Splay Tree:" << endl;
    tree.printTree();

}
