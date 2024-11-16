
#include <iostream>
using namespace std;
#include<stack>
#include<string>
#include<sstream>

stack<int> parseAndPushStack(string str) {
    stack<int> st1;
    string temp = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '-' && str[i + 1] == ' ') {
            st1.push(stoi(temp));
            cout << temp << " - ";
            temp = "";
            i++; // Boşluğu atlamak için i'yi artırıyoruz
        }
        else {
            temp += str[i];
        }
    }
    st1.push(stoi(temp));
    cout << temp << " ";
    return st1;
}

void Question1() {
    string str = "21 - 22 - 24 - 25";
    stack<int> st1;
    string temp = "";
    string empty = st1.empty() ? "Empty" : "Not empty";
    cout << "Check stack initial state: " << empty << endl;

    // Add elements to the stack
    cout << "Add elements to stack: ";
    st1 = parseAndPushStack(str);
    cout << temp << " ";  // Print the last number
    cout << endl;


    cout << "Show stack element (print first in to last in): ";
    stack<int> st2 = st1;
    stack<int> reverseStack;
    while (!st2.empty()) {
        reverseStack.push(st2.top());
        st2.pop();
    }
    while (!reverseStack.empty()) {
        cout << reverseStack.top() << " ";
        reverseStack.pop();
    }
    cout << endl;

    st2 = st1;
    // Show stack element (print last in to first in)
    cout << "Show stack element (print last in to first in): ";
    while (!st2.empty()) {
        cout << st2.top() << " ";
        st2.pop();
    }
    cout << endl;

    cout << "Delete last two elements from stack then show stack elements (print last in to first in): ";
    st1.pop();
    st1.pop();
    st2 = st1;
    while (!st2.empty()) {
        cout << st2.top() << " ";
        st2.pop();
    }
    cout << endl;
}

stack<int> sortStack(stack<int> st1) {
    stack<int> st2;
    while (!st1.empty()) {
        int temp = st1.top();
        st1.pop();
        while (!st2.empty() && st2.top() > temp) {
            st1.push(st2.top());
            st2.pop();
        }
        st2.push(temp);
    }
    return st2;
}

void printStack(stack<int> st1) {
    stack<int> st2 = st1;
    stack<int> reverseStack;
    while (!st2.empty()) {
        reverseStack.push(st2.top());
        st2.pop();
    }
    while (!reverseStack.empty()) {
        cout << reverseStack.top() << " ";
        reverseStack.pop();
    }
    cout << endl;
}


void Question2() {
    stack<int> firstStack, secondStack;
    firstStack.push(10);
    firstStack.push(40);
    firstStack.push(30);
    firstStack.push(20);
    firstStack.push(50);

    // sort the stack
    firstStack = sortStack(firstStack);
    cout << "Sorted stack: ";
    printStack(firstStack);
    cout << endl;

}

bool checkPalindrome(string str) {
    stack<char> st1;
    int middle = str.length() / 2;
    for (int i = 0; i < middle; i++) {
        st1.push(str[i]);
    }
    if (str.length() % 2 != 0) {
        middle++;
    }
    for (int i = middle; i < str.length(); i++) {
        if (str[i] != st1.top()) {
            return false;
        }
        st1.pop();
    }
    return true;
}

void Question3() {
    string str = "level";
    if (checkPalindrome(str)) {
        cout << str << " is a palindrome" << endl;
    }
    else {
        cout << str << " is not a palindrome" << endl;
    }
    str = "hello";
    if (checkPalindrome(str)) {
        cout << str << " is a palindrome" << endl;
    }
    else {
        cout << str << " is not a palindrome" << endl;
    }

}

int main()
{

#if 1
    Question1();
#endif
#if 1
    Question2();
#endif
#if 1
    Question3();
#endif

    return 0;
}