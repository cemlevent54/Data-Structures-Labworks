// Week14_Inclass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;
#include "Map.h"
#include "Set.h"


void displayMenuForMap() {
    cout << "\n===== Map Operations Menu =====" << endl;
    cout << "1. Clear Screen\n2. Insert\n3. Erase\n4. Update\n5. Contains\n6. Count\n7. Find\n8. Lower Bound\n9. Upper Bound\n10. Equal Range\n11. Empty\n12. Size\n13. Clear\n14. Merge\n15. Show\n0. Exit" << endl;
    cout << "Select an option: ";
}


void displayMenuForSet() {
    cout << "\n===== Set Operations Menu =====" << endl;
    cout << "1. Clear Screen\n2. Insert\n3. Erase\n4. Update\n5. Contains\n6. Count\n7. Find\n8. Lower Bound\n9. Upper Bound\n10. Equal Range\n11. Empty\n12. Size\n13. Clear\n14. Merge\n15. Show\n0. Exit" << endl;
    cout << "Select an option: ";
}




void Q1() {
    Set<int> mySet; // Anahtar tipi: int
    int choice, value, newValue;

    while (true) {
        displayMenuForSet();
        cin >> choice;

        switch (choice) {
        case 0: // Exit
            cout << "Exiting...\n";
            return;
        case 1: // Clear Screen
            system("CLS");
            break;
        case 2: { // Insert
            cout << "Enter value to insert: ";
            cin >> value;
            mySet.insert(value);
            cout << "Value inserted.\n";
            break;
        }
        case 3: { // Erase
            cout << "Enter value to erase: ";
            cin >> value;

            if (!mySet.contains(value)) {
                cout << "Value not found.\n";
                break;
            }
            if (mySet.erase(value))
                cout << "Value erased.\n";
            break;
        }
        case 4: { // Update
            cout << "Enter value to update: ";
            cin >> value;
            if (!mySet.contains(value)) {
                cout << "Value not found.\n";
                break;
            }
            cout << "Enter new value: ";
            cin >> newValue;
            mySet.update(value, newValue);
            cout << "Value updated.\n";
            break;
        }
        case 5: { // Contains
            cout << "Enter value to check: ";
            cin >> value;
            cout << (mySet.contains(value) ? "Value exists.\n" : "Value not found.\n");
            break;
        }
        case 6: { // Count
            cout << "Enter value to count: ";
            cin >> value;
            cout << "Count: " << mySet.count(value) << "\n";
            break;
        }
        case 7: { // Find
            cout << "Enter value to find: ";
            cin >> value;
            cout << (mySet.find(value) ? "Value found.\n" : "Value not found.\n");
            break;
        }
        case 8: { // Lower Bound
            cout << "Enter value for lower bound: ";
            cin >> value;
            cout << "Lower bound: " << mySet.lower_bound(value) << "\n";
            break;
        }
        case 9: { // Upper Bound
            cout << "Enter value for upper bound: ";
            cin >> value;
            cout << "Upper bound: " << mySet.upper_bound(value) << "\n";
            break;
        }
        case 10: { // Equal Range
            cout << "Enter value for equal range: ";
            cin >> value;
            auto range = mySet.equal_range(value);
            cout << "Equal range: " << range.first << " to " << range.second << "\n";
            break;
        }
        case 11: // Empty
            cout << (mySet.empty() ? "Set is empty.\n" : "Set is not empty.\n");
            break;
        case 12: // Size
            cout << "Set size: " << mySet.size() << "\n";
            break;
        case 13: // Clear
            mySet.clear();
            cout << "Set cleared.\n";
            break;
        case 14: { // Merge
            Set<int> otherSet;
            int n, tempValue;
            cout << "Enter number of elements for the second set: ";
            cin >> n;

            for (int i = 0; i < n; ++i) {
                cout << "Enter value " << i + 1 << ": ";
                cin >> tempValue;
                otherSet.insert(tempValue);
            }

            mySet.mergeSets(otherSet);
            cout << "Sets merged successfully.\n";
            break;
        }
        case 15: // Show
            mySet.showSet();
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}


void Q2() {
    Map<int, string> myMap; // Anahtar: int, Değer: string
    int choice, key;
    string value;

    while (true) {
        displayMenuForMap();
        cin >> choice;

        switch (choice) {
        case 0: // Exit
            cout << "Exiting...\n";
            return; // Döngüden çıkış
        case 1:
            system("CLS"); // Ekranı temizle
            break;
        case 2: // Insert
            cout << "Enter key (int): ";
            cin >> key;
            cout << "Enter value (string): ";
            cin >> value;


            if (myMap.contains(key)) {
                cout << "Key already exists. Please update instead.\n";
                break;
            }

            myMap.insert(key, value);
            cout << "Item inserted.\n";
            break;
        case 3: // Erase
            cout << "Enter key to erase: ";
            cin >> key;
            if (!myMap.contains(key))
            {
                cout << "Key not found.\n";
                break;
            }
            myMap.erase(key);
            cout << "Item erased.\n";
            break;
        case 4: { // Update
            if (myMap.empty()) {
                cout << "Map is empty. Nothing to update.\n";
                break;
            }

            int oldKey;
            cout << "Enter old key: ";
            cin >> oldKey;

            if (!myMap.contains(oldKey)) {
                cout << "Key not found.\n";
            }

            else {
                cout << "Enter new key: ";
                cin >> key;
                cout << "Enter new value: ";
                cin >> value;
                myMap.update(oldKey, key, value);
                cout << "Item updated.\n";
            }



            break;
        }
        case 5: // Contains
            cout << "Enter key: ";
            cin >> key;
            cout << (myMap.contains(key) ? "Key exists.\n" : "Key not found.\n");
            break;
        case 6: // Count
            cout << "Enter key: ";
            cin >> key;
            cout << "Count: " << myMap.count(key) << "\n";
            break;
        case 7: // Find
            cout << "Enter key to find: ";
            cin >> key;
            cout << (myMap.find(key) ? "Key found.\n" : "Key not found.\n");
            break;
        case 8: { // Lower Bound
            cout << "Enter key: ";
            cin >> key;
            auto value = myMap.lower_bound(key);
            cout << "Lower bound value: " << value << "\n";
            break;
        }
        case 9: { // Upper Bound
            cout << "Enter key: ";
            cin >> key;
            auto value = myMap.upper_bound(key);
            cout << "Upper bound value: " << value << "\n";
            break;
        }
        case 10: { // Equal Range
            cout << "Enter key: ";
            cin >> key;
            auto range = myMap.equal_range(key);
            cout << "Equal range: " << range.first << " to " << range.second << "\n";
            break;
        }
        case 11: // Empty
            cout << (myMap.empty() ? "Map is empty.\n" : "Map is not empty.\n");
            break;
        case 12: // Size
            cout << "Map size: " << myMap.size() << "\n";
            break;
        case 13: // Clear
            myMap.clear();
            cout << "Map cleared.\n";
            break;
        case 14: { // Merge
            Map<int, string> otherMap;
            int n, tempKey;
            string tempValue;
            cout << "How many items to add in the new map? ";
            cin >> n;

            for (int i = 0; i < n; ++i) {
                cout << "Enter key for item " << i + 1 << ": ";
                cin >> tempKey;

                cout << "Enter value for item " << i + 1 << ": ";
                cin >> tempValue;
                otherMap.insert(tempKey, tempValue);
            }
            myMap.merge(otherMap);
            cout << "Maps merged successfully.\n";
            break;
        }
        case 15: // Show
            cout << "Map Contents:\n";
            myMap.show();
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}





int main()
{
#if 1
    Q1();
#endif

#if 0
    Q2();
#endif

}