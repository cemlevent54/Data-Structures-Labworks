// Week12_Inclass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BSTNode.h"
#include "BinarySearchTree.h"
#include "BinarySearchTreeCity.h"
#include "BSTCityNode.h"
#include "AVLNode.h"
#include "AVLTree.h"


void Q1() {
    BSTTree<int> tree;
    while (true) {
        cout << "\n--- Binary Search Tree Menu ---" << endl;
        cout << "1. Insert" << endl;
        cout << "4. InOrder Traversal" << endl;
        cout << "5. PreOrder Traversal" << endl;
        cout << "6. PostOrder Traversal" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Enter value to insert: ";
            int value;
            cin >> value;
            tree.insert(value);
            cout << "Value inserted successfully!" << endl;
            break;
        }
        case 4:
            cout << "In-order Traversal: ";
            tree.inOrder();
            break;
        case 5:
            cout << "Pre-order Traversal: ";
            tree.preOrder();
            break;
        case 6:
            cout << "Post-order Traversal: ";
            tree.postOrder();
            break;
        case 8:
            cout << "Exiting program. Goodbye!" << endl;
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void Q2() {
    BinarySearchTreeCity tree;
    while (true) {
        cout << "\n--- Binary Search Tree City Menu ---" << endl;
        cout << "1. Insert" << endl;
        cout << "2. InOrder Traversal" << endl;
        cout << "3. PreOrder Traversal" << endl;
        cout << "4. PostOrder Traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        // Hatalı giriş kontrolü
        if (cin.fail()) {
            cin.clear();                // Hata bayrağını temizle
            cin.ignore(1000, '\n');     // Geçersiz girdiyi atla
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
            continue;
        }

        switch (choice) {
        case 1: {
            cout << "Enter city name: ";
            string city;
            cin >> city;

            cout << "Enter time: ";
            int time;
            cin >> time;

            if (cin.fail()) { // Geçersiz zaman girdisi kontrolü
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input for time. Please try again." << endl;
            }
            else {
                tree.insert(make_pair(city, time));
                cout << "City inserted successfully!" << endl;
            }
            break;
        }

        case 2: {
            tree.inOrderTraversal();
            break;
        }

        case 3: {
            tree.preOrderTraversal();
            break;
        }

        case 4: {
            tree.postOrderTraversal();
            break;
        }

        case 5: {
            cout << "Exiting program. Goodbye!" << endl;
            return; // Döngüden çıkar
        }

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void Q3() {
    BinarySearchTreeCity mainTree;
    mainTree.insert({ "Bucharest", 5 });
    mainTree.insert({ "Pitesti", 3 });
    mainTree.insert({ "Fagaras", 7 });
    mainTree.insert({ "Rimnicu-Vilcea", 2 });
    mainTree.insert({ "Sibiu", 4 });
    mainTree.insert({ "Urziceni", 6 });
    mainTree.insert({ "Vaslui", 8 });

    cout << "Main Tree (InOrder Traversal): ";
    mainTree.inOrderTraversal();

    // Test1 Tree oluşturuluyor
    BinarySearchTreeCity test1;
    test1.insert({ "Bucharest", 5 });
    test1.insert({ "Pitesti", 3 });
    test1.insert({ "Sibiu", 4 });

    cout << "\nTest1 Tree (InOrder Traversal): ";
    test1.inOrderTraversal();

    // Test2 Tree oluşturuluyor
    BinarySearchTreeCity test2;
    test2.insert({ "Fagaras", 7 });
    test2.insert({ "Sibiu", 4 });

    cout << "\nTest2 Tree (InOrder Traversal): ";
    test2.inOrderTraversal();

    // Test1 alt ağaç kontrolü
    if (mainTree.isSubtree(test1)) {
        cout << "\nTest1: This tree is a subtree of the main tree." << endl;
    }
    else {
        cout << "\nTest1: This tree is NOT a subtree of the main tree." << endl;
    }

    // Test2 alt ağaç kontrolü
    if (mainTree.isSubtree(test2)) {
        cout << "Test2: This tree is a subtree of the main tree." << endl;
    }
    else {
        cout << "Test2: This tree is NOT a subtree of the main tree." << endl;
    }
}

void Q4() {
    AVLTree tree;
    int choice, value;

    while (true) {
        std::cout << "\n[ 1 ] Insert Element Into the Tree\n";
        std::cout << "[ 2 ] Show Balanced AVL Tree\n";
        std::cout << "[ 3 ] InOrder Traversal\n";
        std::cout << "[ 4 ] PreOrder Traversal\n";
        std::cout << "[ 5 ] PostOrder Traversal\n";
        std::cout << "[ 6 ] Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter value to insert: ";
            std::cin >> value;
            tree.insert(value);
            break;
        case 2:
            std::cout << "Balanced AVL Tree (InOrder): ";
            tree.showBalancedTree();
            break;
        case 3:
            std::cout << "InOrder Traversal: ";
            tree.inOrder();
            break;
        case 4:
            std::cout << "PreOrder Traversal: ";
            tree.preOrder();
            break;
        case 5:
            std::cout << "PostOrder Traversal: ";
            tree.postOrder();
            break;
        case 6:
            std::cout << "Exiting...\n";
            return;
        default:
            std::cout << "Invalid choice! Please try again.\n";
        }
    }
}

void Q4_1() {
    AVLTree tree;

    // Elemanları ağaca ekle
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(10);
    tree.insert(25);
    tree.insert(35);
    tree.insert(50);


    std::cout << "Balanced AVL Tree (InOrder): ";
    tree.showBalancedTree();

    std::cout << "\nBalance Factors of all nodes:\n";
    tree.printBalanceFactors();
}

void Q4_2() {
    AVLTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(4);
    tree.insert(6);


    std::cout << "Balanced AVL Tree (InOrder): ";
    tree.showBalancedTree();

    std::cout << "\nBalance Factors of all nodes:\n";
    tree.printBalanceFactors();
}




int main() {
#if 1
    Q1();
#endif

#if 0
    Q2();
#endif

#if 0
    Q3();
#endif

#if 0
    Q4();
#endif

#if 0
    Q4_1();
#endif

#if 0
    Q4_2();
#endif

#if 1

#endif

    return 0;




}
