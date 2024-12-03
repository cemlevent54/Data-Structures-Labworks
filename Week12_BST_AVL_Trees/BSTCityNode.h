#pragma once
#include <iostream>
#include <utility>
#include <string>
using namespace std;

class BSTCityNode {
private:
    pair<string, int> value; // Þehir adý ve sayýsal deðeri
    BSTCityNode* left;       // Sol alt düðüm
    BSTCityNode* right;      // Sað alt düðüm

public:
    // Constructor
    BSTCityNode(pair<string, int> val) : value(val), left(nullptr), right(nullptr) {}

    // Getter ve Setter Metotlarý
    pair<string, int> getValue() { return value; }
    void setValue(pair<string, int> val) { value = val; }

    BSTCityNode* getLeft() { return left; }
    void setLeft(BSTCityNode* node) { left = node; }

    BSTCityNode* getRight() { return right; }
    void setRight(BSTCityNode* node) { right = node; }
};
