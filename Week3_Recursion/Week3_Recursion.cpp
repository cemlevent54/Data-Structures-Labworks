#include <iostream>
using namespace std;


void Question1_A() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int count = 0;

    for (int x = num; x >= 0; x--)
    {
        cout << x << " ";
        count++;
    }

    cout << endl;
}


void Question1_B() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    int x = num;
    int sum = 0;
    while (x > 0)
    {
        sum += x;
        x--;
    }

    cout << "The sum is: " << sum;
    cout << endl;
}

void Question1_C() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int x = num;
    int sum = 0;
    do
    {
        sum += x;
        x--;

    } while (x > 0);

    cout << "The sum is: " << sum;
    cout << endl;
}

void Question2_A(int num) {

    // print first n num from num using recursion
    if (num == 0)
    {
        return;
    }
    else
    {
        Question2_A(num - 1);
        cout << num << " ";
    }


}

int Question2_B(int num) {
    if (num == 0) return 0;
    else return num + Question2_B(num - 1);
}

int Question3(int num) {
    if (num == 1 || num == 0) {
        return 1;
    }
    else return num * Question3(num - 1);
}

int FindFibonacci(int num) {
    if (num == 0) return 0;
    if (num == 1 || num == 2) {
        return 1;
    }
    else return FindFibonacci(num - 1) + FindFibonacci(num - 2);
}


void PrintFibonacci(int current, int max) {
    if (current >= max) return;

    cout << FindFibonacci(current) << " ";
    PrintFibonacci(current + 1, max);
}

void Question4(int n) {
    PrintFibonacci(0, n);
}


int main()
{

#if 1

    Question1_A();
#endif

#if 0
    Question1_B();
#endif

#if 0
    Question1_C();
#endif

#if 0
    cout << "Enter a number: ";
    int num;
    cin >> num;
    cout << "The natural numbers are: ";
    Question2_A(num);
#endif

#if 0
    cout << "Enter a number: ";
    int num;
    cin >> num;
    cout << "The sum of the numbers from 1 to " << num << " is " << Question2_B(num);
#endif

#if 0
    cout << "Enter a number: ";
    int num;
    cin >> num;
    cout << "The factorial of " << num << " is " << Question3(num);
#endif

#if 0
    cout << "Enter a number: ";
    int num;
    cin >> num;
    cout << "The first " << num << " fibonacci numbers are: ";
    Question4(num);
#endif


    return 0;
}
