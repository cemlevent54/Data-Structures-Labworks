// Week9_Queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Week9_Inclass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


class Queue {
private:
    int front;
    int rear;
    int size;
    int capacity;
    int* queue;
public:
    Queue(int capacity) {
        this->capacity = capacity;
        this->front = 0;
        this->rear = -1;
        this->size = 0;
        this->queue = new int[capacity];
    }

    void Enqueue(int value) {
        if (size == capacity) {
            cout << "Queue is full" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = value;
        size++;
    }

    void Dequeue() {
        if (size == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }

    bool IsEmpty() {
        return size == 0;
    }

    bool IsFull() {
        return size == capacity;
    }

    int Count() {
        return size;
    }

    void Display() {
        if (size == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        int i = front;
        for (int j = 0; j < size; j++) {
            cout << queue[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }

    void Clear() {
        front = 0;
        rear = -1;
        size = 0;
    }

    int Front() {
        if (size == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return queue[front];
    }

    int Rear() {
        if (size == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return queue[rear];
    }

    void Sort() {
        if (size == 0) {
            cout << "Queue is empty" << endl;
            return;
        }

        // Step 1: Copy elements from the queue to a temporary vector
        vector<int> temp;
        int i = front;
        for (int j = 0; j < size; j++) {
            temp.push_back(queue[i]);
            i = (i + 1) % capacity;
        }

        // Step 2: Sort the vector
        sort(temp.begin(), temp.end());

        // Step 3: Clear the queue and reinsert sorted elements
        Clear();
        for (int val : temp) {
            Enqueue(val);
        }
    }

    ~Queue() {
        delete[] queue;
    }
};

void Q1() {
    int option;
    Queue queue(5);

    while (1) {
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. IsEmpty()" << endl;
        cout << "4. IsFull()" << endl;
        cout << "5. Count()" << endl;
        cout << "6. Display()" << endl;
        cout << "7. Clear Screen" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your option: ";
        cin >> option;

        switch (option) {
        case 0:
            return;

        case 1: {
            int value;
            cout << "Enter the value to Enqueue: ";
            cin >> value;
            queue.Enqueue(value);
            queue.Display();
            break;
        }

        case 2:
            queue.Dequeue();
            queue.Display();
            break;

        case 3:
            if (queue.IsEmpty()) {
                cout << "Queue is empty" << endl;
            }
            else {
                cout << "Queue is not empty" << endl;
            }
            break;

        case 4:
            if (queue.IsFull()) {
                cout << "Queue is full" << endl;
            }
            else {
                cout << "Queue is not full" << endl;
            }
            break;

        case 5:
            cout << "Count: " << queue.Count() << endl;
            break;

        case 6:
            queue.Display();
            break;

        case 7:
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
            break;

        default:
            cout << "Invalid option, please try again." << endl;
            break;
        }
    }
}

bool isPalindrome_w_stack_and_queue(string str) {
    stack<char> stack;
    queue<char> queue;
    for (int i = 0; i < str.length(); i++) {
        stack.push(str[i]);
    }
    for (int i = 0; i < str.length(); i++) {
        queue.push(str[i]);
    }
    while (!stack.empty() && !queue.empty()) {
        if (stack.top() != queue.front()) {
            return false;
        }
        stack.pop();
        queue.pop();
    }
    return true;
}

bool isPalindrome(string str) {
    for (int i = 0; i < str.length() / 2; i++) {
        if (str[i] != str[str.length() - 1 - i]) {
            return false;
        }
    }
    return true;
}

bool isPalindrome_w_stack(string str) {
    stack<char> stack;
    for (int i = 0; i < str.length(); i++) {
        stack.push(str[i]);
    }
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != stack.top()) {
            return false;
        }
        stack.pop();
    }
    return true;
}

bool isPalindrome_w_queue(const string& str) {
    queue<char> queue;

    for (char ch : str) {
        queue.push(ch);
    }

    // Compare each character from the beginning of the string with the front of the queue
    for (int i = str.length() - 1; i >= 0; i--) {
        if (str[i] != queue.front()) {
            return false;
        }
        queue.pop();
    }

    return true;
}

void Q2() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    bool result = isPalindrome_w_stack_and_queue(str);
    // give me tests
    cout << "isPalindrome with stack and queue: " << result << endl;

    result = isPalindrome(str);
    cout << "isPalindrome: " << result << endl;

    result = isPalindrome_w_stack(str);
    cout << "isPalindrome with stack: " << result << endl;

    result = isPalindrome_w_queue(str);
    cout << "isPalindrome with queue: " << result << endl;

}

// Function to find the index of the minimum element within the unsorted part of the queue
int minIndex(queue<int>& queue, int sortedIndex) {
    int min_index = -1;
    int min_val = INT_MAX;
    int n = queue.size();

    for (int i = 0; i < n; i++) {
        int current = queue.front();
        queue.pop();

        // Check if current element is the minimum in the unsorted part of the queue
        if (current <= min_val && i <= sortedIndex) {
            min_index = i;
            min_val = current;
        }
        queue.push(current); // Push element back into the queue
    }
    return min_index;
}

// Function to move the minimum element found at minIndex to the rear of the queue
void insertMinToRear(queue<int>& queue, int minIndex) {
    int min_val;
    int n = queue.size();

    for (int i = 0; i < n; i++) {
        int current = queue.front();
        queue.pop();

        // Only push back elements that are not at minIndex
        if (i != minIndex) {
            queue.push(current);
        }
        else {
            min_val = current; // Store the minimum value
        }
    }
    queue.push(min_val); // Place minimum element at the rear
}

// Function to sort the queue in ascending order
void sortQueue(queue<int>& queue) {
    int n = queue.size();

    // Move the smallest element to the rear in each iteration
    for (int i = 1; i <= n; i++) {
        int min_index = minIndex(queue, n - i);
        insertMinToRear(queue, min_index);
    }
}

// Function to execute sorting and display the sorted queue
void Q3() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    queue<int> queue;

    // Input elements into the queue
    for (int i = 0; i < size; i++) {
        int element;
        cout << "Enter the element: ";
        cin >> element;
        queue.push(element);
    }

    // Sort the queue
    sortQueue(queue);

    // Display the sorted queue
    cout << "Sorted Queue: ";
    while (!queue.empty()) {
        cout << queue.front() << " ";
        queue.pop();
    }
    cout << endl;
}


int main()
{
    std::cout << "Week 9 Inclass\n";

#if 1
    Q1();
#endif
#if 0
    Q2();
#endif
#if 0
    Q3();
#endif


    return 0;
}
