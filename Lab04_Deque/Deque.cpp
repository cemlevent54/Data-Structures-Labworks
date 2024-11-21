#include "Deque.h"

///------------------------------------------------------
/// Default constructor
/// 
Deque::Deque() {
	// Fill this in
	head = tail = NULL;
	noOfItems = 0;
} //end-Deque

///------------------------------------------------------
/// Destructor
/// 
Deque::~Deque() {
	// Fill this in
	while (!IsEmpty()) {
		RemoveFront();
	}
} //end-~Deque

///------------------------------------------------------
/// Adds a new item to the front of the Deque
/// 
void Deque::AddFront(int item) {
	// Fill this in
	DequeNode* newNode = new DequeNode(item);
	if (IsEmpty()) {
		head = tail = newNode;
	}
	else {
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	noOfItems++;
} //end-AddFront

///------------------------------------------------------
/// Adds a new item to the end of the Deque
/// 
void Deque::AddRear(int item) {
	// Fill this in
	DequeNode* newNode = new DequeNode(item);
	if (IsEmpty()) {
		head = tail = newNode;
	}
	else {
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
	noOfItems++;
} //end-AddRear

///------------------------------------------------------
/// Remove and return the item at the front of the Deque
/// If the Deque is empty, throw an exception
/// 
int Deque::RemoveFront() {
	// Fill this in
	if (IsEmpty()) {
		throw "Deque is empty! Cannot remove from front.";
	}
	int item = head->item;
	DequeNode* temp = head;
	head = head->next;
	if (head) {
		head->prev = NULL;
	}
	else {
		tail = NULL;
	}
	delete temp;
	noOfItems--;
	return item;
} //end-RemoveFront

///------------------------------------------------------
/// Remove and return the item at the rear of the Deque
/// If the Deque is empty, throw an exception
/// 
int Deque::RemoveRear() {
	// Fill this in
	if (IsEmpty()) {
		throw "Deque is empty! Cannot remove from rear.";
	}
	int item = tail->item;
	DequeNode* temp = tail;
	tail = tail->prev;
	if (tail) {
		tail->next = NULL;
	}
	else {
		head = NULL;
	}
	delete temp;
	noOfItems--;
	return item;
} //end-RemoveRear

///------------------------------------------------------
/// Return the item at the front of the Deque (do not remove the item)
/// If the Deque is empty, throw an exception
/// 
int Deque::Front() {
	// Fill this in
	if (IsEmpty()) {
		throw "Deque is empty! Cannot return front.";
	}
	return head->item;
} //end-Front

///------------------------------------------------------
/// Return the item at the rear of the Deque (do not remove the item)
/// If the Deque is empty, throw an exception
/// 
int Deque::Rear() {
	// Fill this in
	if (IsEmpty()) {
		throw "Deque is empty! Cannot return rear.";
	}
	return tail->item;
} //end-Rear
