#include <string>
#include <iostream>
#include <stack>
#include <sstream>
#include <unordered_map>
using namespace std;

///----------------------------------------------------------------------------------
/// Given an expression in infix-notation, converts it to a string in post-fix notation 
/// 
int getPrecedence(char op) {
    unordered_map<char, int> precedence;
    precedence['+'] = precedence['-'] = 1;  // Düþük öncelik
    precedence['*'] = precedence['/'] = 2;  // Yüksek öncelik

    return precedence[op];
}

string Infix2Postfix(string& s) {
    // Fill this in
    stack<char> operatorStack;  // Operatörler için yýðýn
    string result;              // Postfix sonucu

    for (char c : s) {
        if (isspace(c)) continue;  // Boþluklarý atla
        else if (isdigit(c)) result += c;  // Sayýlarý sonuca ekle
        else if (c == '(') operatorStack.push(c);  // '(' yýðýna ekle
        else if (c == ')') {  // '(' görünene kadar iþle
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                result += ' ';
                result += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop();  // '(' çýkart
        }
        else {  // Operatörleri iþle
            result += ' ';
            while (!operatorStack.empty() && getPrecedence(operatorStack.top()) >= getPrecedence(c)) {
                result += operatorStack.top();
                operatorStack.pop();
                result += ' ';
            }
            operatorStack.push(c);
        }
    }

    // Kalan operatörleri çýkart
    while (!operatorStack.empty()) {
        result += ' ';
        result += operatorStack.top();
        operatorStack.pop();
    }

    return result;  // Postfix ifadeyi döndür
} // end-Infix2Postfix

///----------------------------------------------------------------------------------
/// Given a string in post-fix notation, evaluates it and returns the result
/// 
/// 
bool IsOperator(char C) {
    return C == '+' || C == '-' || C == '*' || C == '/';
}

int EvaluatePostfixExpression(string& s) {
    stack<int> operandStack;  // Operatörler için yýðýn

    stringstream ss(s);  // Ayrýþtýrma için stringstream kullan
    string token;

    while (ss >> token) {
        // Sayýlarý yýðýna ekle
        if (isdigit(token[0]) || (token.length() > 1 && isdigit(token[1]))) {
            operandStack.push(stoi(token));
        }
        // Operatörleri iþle
        else if (IsOperator(token[0])) {
            int operand2 = operandStack.top(); operandStack.pop();
            int operand1 = operandStack.top(); operandStack.pop();

            switch (token[0]) {
            case '+': operandStack.push(operand1 + operand2); break;
            case '-': operandStack.push(operand1 - operand2); break;
            case '*': operandStack.push(operand1 * operand2); break;
            case '/': operandStack.push(operand1 / operand2); break;
            }
        }
    }

    return operandStack.top();  // Son sonucu döndür
} // end-EvaluatePostfixExpression
