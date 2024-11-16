#include <iostream>
#include <chrono>
using namespace std;





int main() {

	// Question 1 - input elements in 1 dim array
	cout << "Question 1: " << endl;
	int testCases;
	cout << "Enter the number of test cases: ";
	cin >> testCases;

	for (int i = 0; i < testCases; i++) {
		int numberofElement;
		int operationCount = 0; // To track the number of basic operations
		cout << "Enter the number of elements: ";
		cin >> numberofElement;

		int* arr = new int[numberofElement];
		cout << "Enter the elements of the array: ";
		for (int i = 0; i < numberofElement; i++) {
			cin >> arr[i];
		}

		auto start = chrono::high_resolution_clock::now(); // Start timing

		for (int i = 0; i < numberofElement; i++) {
			cout << arr[i] << " ";
			operationCount++; // Increment the operation count for each output
		}
		cout << endl;

		auto end = chrono::high_resolution_clock::now(); // End timing
		auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

		cout << "Time taken during the output process: " << float(duration.count()) << " milliseconds" << endl;

		// Check complexity based on the number of operations performed
		if (operationCount == numberofElement) {
			cout << "Complexity is O(n)" << endl; // Linear complexity
		}
		else if (operationCount == 1) {
			cout << "Complexity is O(1)" << endl; // Constant complexity
		}

		cout << endl;
		delete[] arr;
		arr = nullptr;
	}

	// Question 2 - input elements in 2 dim array
	cout << "Question 2: " << endl;
	cout << "Enter the number of test cases: ";
	cin >> testCases;
	for (int i = 0; i < testCases; i++) {
		int row, col;
		cout << "Enter the number of rows: ";
		cin >> row;
		cout << "Enter the number of columns: ";
		cin >> col;

		int** arr = new int* [row];
		for (int i = 0; i < row; i++) {
			arr[i] = new int[col];
		}

		cout << "Enter the elements of the array: ";
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cin >> arr[i][j];
			}
		}

		auto start = chrono::high_resolution_clock::now(); // Start timing

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}

		auto end = chrono::high_resolution_clock::now(); // End timing
		auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

		cout << "Time taken during the output process: " << float(duration.count()) << " milliseconds" << endl;


		if (row == 1 && col == 1) {
			cout << "Complexity is O(1)" << endl;
		}
		else if (row == 1 || col == 1) {
			cout << "Complexity is O(n)" << endl;
		}
		else if (row == col) {
			cout << "Complexity is O(n^2)" << endl;
		}

		cout << endl;
		for (int i = 0; i < row; i++) {
			delete[] arr[i];
		}
		delete[] arr;
		arr = nullptr;
	}

	// question 3 - input elements in 3 dim array
	cout << "Question 3: " << endl;
	cout << "Enter the number of test cases: ";
	cin >> testCases;

	for (int i = 0; i < testCases; i++) {
		int row, col, depth;
		cout << "Enter the number of rows: ";
		cin >> row;
		cout << "Enter the number of columns: ";
		cin >> col;
		cout << "Enter the depth: ";
		cin >> depth;

		int*** arr = new int** [row];
		for (int i = 0; i < row; i++) {
			arr[i] = new int* [col];
			for (int j = 0; j < col; j++) {
				arr[i][j] = new int[depth];
			}
		}

		cout << "Enter the elements of the array: ";
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				for (int k = 0; k < depth; k++) {
					cin >> arr[i][j][k];
				}
			}
		}

		auto start = chrono::high_resolution_clock::now(); // Start timing

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				for (int k = 0; k < depth; k++) {
					cout << arr[i][j][k] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}

		auto end = chrono::high_resolution_clock::now(); // End timing
		auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

		cout << "Time taken during the output process: " << float(duration.count()) << " milliseconds" << endl;

		// Check complexity based on the number of operations performed
		if (row == 1 && col == 1 && depth == 1) {
			cout << "Complexity is O(1)" << endl;
		}
		else if (row == 1 || col == 1 || depth == 1) {
			cout << "Complexity is O(n)" << endl;
		}
		else if (row == col && col == depth) {
			cout << "Complexity is O(n^3)" << endl;
		}

		cout << endl;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				delete[] arr[i][j];
			}
			delete[] arr[i];
		}
	}

	return 0;
}
