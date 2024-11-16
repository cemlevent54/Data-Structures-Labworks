#include <iostream>
using namespace std;
#include<list>
#include<vector>
#include <type_traits>

double factorial_recursive(int n) {
    if (n == 0) return 1;
    return n * factorial_recursive(n - 1);
}

double factorial_iteration(int n) {
    double result;
    for (result = 1; n > 1; n--) {
        result *= n;
    }
    return result;
}

void Question1_A() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << "Factorial of " << number << " using Recursion is " << factorial_recursive(number) << endl;
}

void Question1_B() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << "Factorial of " << number << " using Iteration is " << factorial_iteration(number) << endl;
}

void Question2_A() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    for (int i = 1; i < 11; i++) {
        cout << number << " * " << i << " = " << number * i << endl;
    }
}

void Question2_B() {
    int number, range;
    cout << "Enter a number: ";
    cin >> number;
    cout << "Enter a range: ";
    cin >> range;
    for (int i = 1; i < range + 1; i++) {
        cout << number << " * " << i << " = " << number * i << endl;
    }
}

template<typename T>
void Question3() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    vector<T> arrayList;
    list<T> linkedList;
    for (int i = 0; i < n + 1; i++) {
        if constexpr (std::is_same<T, char>::value) {
            // If T is char, store characters starting from 'A'
            arrayList.push_back(static_cast<T>('A' + i));
            linkedList.push_back(static_cast<T>('A' + i));
        }
        else {
            // For other types, store numeric values
            arrayList.push_back(static_cast<T>(i));
            linkedList.push_back(static_cast<T>(i));
        }
    }

    cout << "Vector: " << endl;
    int index = 0;
    for (auto i = arrayList.begin(); i != arrayList.end(); i++) {
        cout << "arrayList[" << index << "] = " << *i << " ,Address = " << static_cast<const void*>(&(*i)) << " " << endl;
        index++;
    }
    index = 0;
    cout << endl;
    cout << "List: " << endl;
    for (auto i = linkedList.begin(); i != linkedList.end(); i++) {
        cout << "linkedList[" << index << "] = " << *i << " ,Address = " << static_cast<const void*>(&(*i)) << " " << endl;
        index++;
    }
    cout << endl;
}

void Question3() {
    Question3<char>();
}


void Question4() {
    int number;
    cout << "Enter a number: ";
    cin >> number;


    // contigous allocation
    int* data = new int[number * number];

    int** arr = new int* [number];
    for (int i = 0; i < number; i++) {
        arr[i] = &data[i * number];
    }

    int num = 100;
    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++) {
            arr[i][j] = num;
            num += 4;
        }
    }

    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++) {
            cout << "&arr[" << i << "][" << j << "] = " << arr[i][j] << " ,Address = " << static_cast<const void*>(&arr[i][j]) << " " << endl;
        }
    }

    delete[] data;
    delete[] arr;

}

int main()
{
    cout << "Hello World!\n";
#if 0
    Question1_A();
#endif

#if 0
    Question1_B();
#endif

#if 0
    Question2_A();
#endif

#if 0
    Question2_B();
#endif

#if 0
    Question3();
#endif

#if 1
    Question4();
#endif
    return 0;
}