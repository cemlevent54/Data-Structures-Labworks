#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Poly.h"
#include "PolyNode.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

//-------------------------------------------------
// Creates a polynomial from an expression.
// Returns a pointer to the first PolyNode in the list (head of the list)
//
// Expression will be of the following sort:
// Ex1: 2.3x^4 + 5x^3 - 2.64x - 4
// Ex2: -4.555x^10 - 45.44
// Ex3: x^6 + 2x^4 - x^3 - 6.3x + 4.223 
// Ex4: 34
// Ex5: -x+1
// Ex6: -3x^4    +   4x
// Ex7: -2x  - 5
//

PolyNode* CreatePoly(char* expr) {
    // Assuming expr is a valid polynomial expression, parse and create the polynomial linked list
    PolyNode* head = nullptr;
    std::string input(expr);
    std::vector<std::string> terms;
    std::string term;
    for (char c : input) {
        if (c == '+' || c == '-') {
            if (!term.empty()) {
                terms.push_back(term);
            }
            term = c;
        }
        else {
            term += c;
        }
    }
    if (!term.empty()) {
        terms.push_back(term);
    }

    for (auto& t : terms) {
        t.erase(std::remove(t.begin(), t.end(), ' '), t.end()); // Remove whitespace
        double coef = 1.0;
        int exp = 0;
        size_t xPos = t.find('x');
        if (xPos != std::string::npos) {
            if (xPos == 0 || (xPos == 1 && t[0] == '+')) {
                coef = 1.0;
            }
            else if (xPos == 1 && t[0] == '-') {
                coef = -1.0;
            }
            else {
                coef = atof(t.substr(0, xPos).c_str());
            }

            size_t caretPos = t.find('^');
            if (caretPos != std::string::npos) {
                exp = atoi(t.substr(caretPos + 1).c_str());
            }
            else {
                exp = 1;
            }
        }
        else {
            coef = atof(t.c_str());
            exp = 0;
        }

        head = AddNode(head, coef, exp);
    }

    return head;
} // end-CreatePoly

void DeletePoly(PolyNode* poly) {
    while (poly != nullptr) {
        PolyNode* temp = poly;
        poly = poly->next;
        delete temp;
    }
} // end-DeletePoly

//-------------------------------------------------
// Adds a node (coefficient, exponent) to poly. If there already 
// is a node with the same exponent, then you simply add the coefficient
// to the existing coefficient. If not, you add a new node to polynomial
// Returns a pointer to the possibly new head of the polynomial.
//

PolyNode* AddNode(PolyNode* head, double coef, int exp) {
    // If coefficient is zero, no need to add a node
    if (coef == 0) {
        return head;
    }

    // Create a new node
    PolyNode* newNode = new PolyNode;
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = nullptr;

    // If the list is empty or the new node should be inserted at the beginning
    if (head == nullptr || head->exp < exp) {
        newNode->next = head;
        return newNode;
    }

    // Find the correct position to insert the new node
    PolyNode* current = head;
    while (current->next != nullptr && current->next->exp > exp) {
        current = current->next;
    }

    // If a node with the same exponent is found, add the coefficients
    if (current->exp == exp) {
        current->coef += coef;
        delete newNode; // No need for the new node
    }
    else if (current->next != nullptr && current->next->exp == exp) {
        current->next->coef += coef;
        delete newNode; // No need for the new node
    }
    else {
        // Insert the new node in the correct position
        newNode->next = current->next;
        current->next = newNode;
    }

    return head;
} // end-AddNode 

//-------------------------------------------------
// Adds two polynomials and returns a new polynomial that contains the result
// Computes: poly3 = poly1 + poly2 and returns poly3
//
PolyNode* Add(PolyNode* poly1, PolyNode* poly2) {
    // Fill this in
    PolyNode* result = new PolyNode;
    result->next = nullptr;
    PolyNode* current = result;
    PolyNode* p1 = poly1;
    PolyNode* p2 = poly2;
    while (p1 != nullptr && p2 != nullptr) {
        if (p1->exp == p2->exp) {
            double sum = p1->coef + p2->coef;
            if (sum != 0) {
                current->next = new PolyNode;
                current = current->next;
                current->coef = sum;
                current->exp = p1->exp;
                current->next = nullptr;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp) {
            current->next = new PolyNode;
            current = current->next;
            current->coef = p1->coef;
            current->exp = p1->exp;
            current->next = nullptr;
            p1 = p1->next;
        }
        else {
            current->next = new PolyNode;
            current = current->next;
            current->coef = p2->coef;
            current->exp = p2->exp;
            current->next = nullptr;
            p2 = p2->next;
        }
    }
    while (p1 != nullptr) {
        current->next = new PolyNode;
        current = current->next;
        current->coef = p1->coef;
        current->exp = p1->exp;
        current->next = nullptr;
        p1 = p1->next;
    }
    while (p2 != nullptr) {
        current->next = new PolyNode;
        current = current->next;
        current->coef = p2->coef;
        current->exp = p2->exp;
        current->next = nullptr;
        p2 = p2->next;
    }
    PolyNode* temp = result;
    result = result->next;
    delete temp;
    return result;
} //end-Add

//-------------------------------------------------
// Subtracts poly2 from poly1 and returns the resulting polynomial
// Computes: poly3 = poly1 - poly2 and returns poly3
//
PolyNode* Subtract(PolyNode* poly1, PolyNode* poly2) {
    // Fill this in
    PolyNode* result = new PolyNode;
    result->next = nullptr;
    PolyNode* current = result;
    PolyNode* p1 = poly1;
    PolyNode* p2 = poly2;
    while (p1 != nullptr && p2 != nullptr) {
        if (p1->exp == p2->exp) {
            double diff = p1->coef - p2->coef;
            if (diff != 0) {
                current->next = new PolyNode;
                current = current->next;
                current->coef = diff;
                current->exp = p1->exp;
                current->next = nullptr;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp) {
            current->next = new PolyNode;
            current = current->next;
            current->coef = p1->coef;
            current->exp = p1->exp;
            current->next = nullptr;
            p1 = p1->next;
        }
        else {
            current->next = new PolyNode;
            current = current->next;
            current->coef = -p2->coef;
            current->exp = p2->exp;
            current->next = nullptr;
            p2 = p2->next;
        }
    }
    while (p1 != nullptr) {
        current->next = new PolyNode;
        current = current->next;
        current->coef = p1->coef;
        current->exp = p1->exp;
        current->next = nullptr;
        p1 = p1->next;
    }
    while (p2 != nullptr) {
        current->next = new PolyNode;
        current = current->next;
        current->coef = -p2->coef;
        current->exp = p2->exp;
        current->next = nullptr;
        p2 = p2->next;
    }
    PolyNode* temp = result;
    result = result->next;
    delete temp;
    return result;
} //end-Substract

//-------------------------------------------------
// Multiplies poly1 and poly2 and returns the resulting polynomial
// Computes: poly3 = poly1 * poly2 and returns poly3
//
PolyNode* Multiply(PolyNode* poly1, PolyNode* poly2) {
    // Fill this in
    PolyNode* result = new PolyNode;
    result->next = nullptr;
    PolyNode* current = result;
    PolyNode* p1 = poly1;
    PolyNode* p2 = poly2;
    while (p1 != nullptr) {
        while (p2 != nullptr) {
            double coef = p1->coef * p2->coef;
            int exp = p1->exp + p2->exp;
            current->next = new PolyNode;
            current = current->next;
            current->coef = coef;
            current->exp = exp;
            current->next = nullptr;
            p2 = p2->next;
        }
        p1 = p1->next;
        p2 = poly2;
    }
    PolyNode* temp = result;
    result = result->next;
    delete temp;
    return result;


} //end-Multiply

//-------------------------------------------------
// Evaluates the polynomial at a particular "x" value and returns the result
//
double Evaluate(PolyNode* poly, double x) {
    // Fill this in
    double result = 0;
    PolyNode* current = poly;
    while (current != nullptr) {
        result += current->coef * pow(x, current->exp);
        current = current->next;
    }
    return result;
} //end-Evaluate

//-------------------------------------------------
// Computes the derivative of the polynomial and returns it
// Ex: poly(x) = 3x^4 - 2x + 1-->Derivative(poly) = 12x^3 - 2
//
PolyNode* Derivative(PolyNode* poly) {
    // Fill this in
    PolyNode* result = new PolyNode;
    result->next = nullptr;
    PolyNode* current = result;
    PolyNode* p = poly;
    while (p != nullptr) {
        if (p->exp > 0) {
            current->next = new PolyNode;
            current = current->next;
            current->coef = p->coef * p->exp;
            current->exp = p->exp - 1;
            current->next = nullptr;
        }
        p = p->next;
    }
    PolyNode* temp = result;
    result = result->next;
    delete temp;
    return result;
} //end-Derivative

//-------------------------------------------------
// Plots the polynomial in the range [x1, x2].
// -39<=x1<x2<=39
// -12<=y<=12
// On the middle of the screen you gotta have x & y axis plotted
// During evaluation, if "y" value does not fit on the screen,
// then just skip it. Otherwise put a '*' char depicting the curve
//
void Plot(PolyNode* poly, int x1, int x2) {
    // Ensure the range is within valid limits
    if (x1 < -39 || x2 > 39 || x1 >= x2) {
        std::cout << "Invalid range. x1 should be >= -39, x2 <= 39, and x1 < x2." << std::endl;
        return;
    }

    for (int y = 12; y >= -12; y--) {
        for (int x = x1; x <= x2; x++) {
            double result = Evaluate(poly, x);
            if (std::round(result) == y) {
                std::cout << "*";
            }
            else if (y == 0 && x == 0) {
                std::cout << "+";
            }
            else if (y == 0) {
                std::cout << "-";
            }
            else if (x == 0) {
                std::cout << "|";
            }
            else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
} // end-Plot
