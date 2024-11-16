#include <iostream>
using namespace std;
#include<list>
#include<chrono>



list<int> FindUnionofTwoGivenList(list<int> list1, list<int> list2) {
	// find ordered union of two lists
	list<int> listunion;
	list<int>::iterator it1 = list1.begin();
	list<int>::iterator it2 = list2.begin();
	while (it1 != list1.end() && it2 != list2.end()) {
		if (*it1 < *it2) {
			listunion.push_back(*it1);
			it1++;
		}
		else if (*it1 > *it2) {
			listunion.push_back(*it2);
			it2++;
		}
		else {
			listunion.push_back(*it1);
			it1++;
			it2++;
		}
	}
	while (it1 != list1.end()) {
		listunion.push_back(*it1);
		it1++;
	}
	while (it2 != list2.end()) {
		listunion.push_back(*it2);
		it2++;
	}

	return listunion;
}

void printList(list<int> list) {
	for (int i : list) {
		cout << i << " ";
	}
	cout << endl;
}

void Question1_A() {
	// find ordered union of two lists
	list<int> list1 = { 1, 2, 3, 4, 5 };
	list<int> list2 = { 3, 4, 5, 6, 7 };
	list<int> listunion = FindUnionofTwoGivenList(list1, list2);
	cout << "list1: ";  printList(list1);
	cout << "list2: ";   printList(list2);
	cout << "listunion: ";   printList(listunion);
}

struct Node {
	int val;
	Node* next;
	Node* prev;
	Node(int value = 0) : val(value), next(nullptr), prev(nullptr) {}
};


// write a functions that append a node to the end of a double linked list
void append(Node*& head, Node*& tail, int value) {
	Node* newNode = new Node(value);
	if (head == nullptr) {
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}

Node* findUnionOfTwoDoubleLinkedList(Node* head1, Node* tail1, Node* head2, Node* tail2) {
	Node* headunion = nullptr;
	Node* tailunion = nullptr;
	Node* it1 = head1;
	Node* it2 = head2;
	while (it1 != nullptr && it2 != nullptr) {
		if (it1->val < it2->val) {
			append(headunion, tailunion, it1->val);
			it1 = it1->next;
		}
		else if (it1->val > it2->val) {
			append(headunion, tailunion, it2->val);
			it2 = it2->next;
		}
		else {
			append(headunion, tailunion, it1->val);
			it1 = it1->next;
			it2 = it2->next;
		}
	}
	while (it1 != nullptr) {
		append(headunion, tailunion, it1->val);
		it1 = it1->next;
	}
	while (it2 != nullptr) {
		append(headunion, tailunion, it2->val);
		it2 = it2->next;
	}
	return headunion;
}

void printDoubleLinkedList(Node* head) {
	Node* it = head;
	while (it != nullptr) {
		cout << it->val << " ";
		it = it->next;
	}
	cout << endl;
}

void Question1_B() {
	Node* head1 = nullptr;
	Node* tail1 = nullptr;
	for (int i = 1; i < 6; i++) {
		append(head1, tail1, i);
	}
	Node* head2 = nullptr;
	Node* tail2 = nullptr;
	for (int i = 3; i < 8; i++) {
		append(head2, tail2, i);
	}
	Node* headunion = findUnionOfTwoDoubleLinkedList(head1, tail1, head2, tail2);
	cout << "list1: ";  printDoubleLinkedList(head1);
	cout << "list2: ";  printDoubleLinkedList(head2);
	cout << "listunion: "; printDoubleLinkedList(headunion);
}


void Question1_C() {
	// compare Question1_A and Question1_B
	// find ordered union of two lists
	auto start = chrono::high_resolution_clock::now();
	Question1_A();
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
	cout << "Time taken by list: " << duration.count() << " microseconds" << endl;

	auto start1 = chrono::high_resolution_clock::now();
	// define two sorted double linked lists and union them
	Node* head1 = nullptr;
	Node* tail1 = nullptr;
	Question1_B();
	auto end1 = chrono::high_resolution_clock::now();
	auto duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start1);
	cout << "Time taken by double linked list: " << duration1.count() << " microseconds" << endl;

	// compare two time
	if (duration.count() < duration1.count()) {
		cout << "list is faster" << endl;
	}
	else {
		cout << "double linked list is faster" << endl;
	}
}

template <typename T>
bool isPalindrome(std::list<T> linkedList) {
	auto it1 = linkedList.begin();
	auto it2 = linkedList.end();
	if (it2 != linkedList.begin()) {
		it2--;  // En son elemanı gösterecek şekilde ayarlıyoruz
	}
	while (it1 != it2 && std::next(it1) != it2) {
		if (*it1 != *it2) {
			return false;
		}
		it1++;
		it2--;
	}
	return true;
}


void Question2() {
	// check if a linked list is palindrome
	list<int> linkedList = { 1, 2, 3, 2, 1 };
	if (isPalindrome(linkedList)) {
		cout << "linked list is palindrome" << endl;
	}
	else {
		cout << "linked list is not palindrome" << endl;
	}
	list<int> linkedList1 = { 1, 2, 3, 4, 5 };
	if (isPalindrome(linkedList1)) {
		cout << "linked list is palindrome" << endl;
	}
	else {
		cout << "linked list is not palindrome" << endl;
	}
	list<char> linkedList2 = { 'a', 'b', 'c', 'b', 'a' };
	if (isPalindrome(linkedList2)) {
		cout << "linked list is palindrome" << endl;
	}
	else {
		cout << "linked list is not palindrome" << endl;
	}
	list<char> linkedList3 = { 'a', 'b', 'c', 'd', 'e' };
	if (isPalindrome(linkedList3)) {
		cout << "linked list is palindrome" << endl;
	}
	else {
		cout << "linked list is not palindrome" << endl;
	}
}

bool binarySearchInLinkedList(list<int> list1, int searchval) {
	if (list1.empty()) {
		return false;
	}

	auto it1 = list1.begin(); // Başlangıç iteratoru
	auto it2 = list1.end();   // Bitiş iteratoru (burası son elemandan sonrasını gösteriyor)

	while (it1 != it2) {
		// Listenin ortasına ulaşmak için iterator'u ilerletiyoruz
		auto itmid = it1;
		int distance = std::distance(it1, it2);
		std::advance(itmid, distance / 2);

		if (*itmid == searchval) {
			return true;
		}
		else if (*itmid < searchval) {
			// Eğer aradığımız değer ortadaki değerden büyükse, aramayı sağ tarafa kaydırıyoruz
			it1 = std::next(itmid);
		}
		else {
			// Eğer aradığımız değer ortadaki değerden küçükse, aramayı sol tarafa kaydırıyoruz
			it2 = itmid;
		}
	}

	return false;
}

void Question3() {
	// binary search in linked list
	list<int> list1 = { 1,2,3,4,5,6 };
	int searchval = 7;
	if (binarySearchInLinkedList(list1, searchval)) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

}

int main()
{
#if 1
	// find ordered union of two lists
	Question1_A();
#endif
#if 0
	// find ordered union of two double linked lists
	Question1_B();
#endif
#if 0
	// compare Question1_A and Question1_B
	Question1_C();
#endif
#if 0
	// check if a linked list is palindrome
	Question2();
#endif
#if 1
	// binary search method. in linked list
	Question3();
#endif


	return 0;
}