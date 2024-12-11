#include "ThreadedBST.h"

///-----------------------------------------------
/// Erases all nodes in the tree
/// 
void ThreadedBST::eraseTreeNodes(BSTNode* node) {
	BSTNode* curr = this->min();

	while (curr != NULL) {
		BSTNode* n = this->next(curr);
		delete curr;
		curr = n;
	} // end-while
} //end-eraseTreeNodes

///-----------------------------------------------
/// Adds a given key to the BST
/// 
void ThreadedBST::add(int key) {
	// Fill this in
	BSTNode* newNode = new BSTNode(key);

	if (root == NULL) {
		root = newNode;
		return;
	}

	BSTNode* curr = root;
	while (true) {
		if (key < curr->key) {
			if (curr->leftLinkType == THREAD) {
				newNode->left = curr->left;
				newNode->right = curr;
				curr->left = newNode;
				curr->leftLinkType = CHILD;
				return;
			}
			else {
				curr = curr->left;
			}
		}
		else if (key > curr->key) {
			if (curr->rightLinkType == THREAD) {
				newNode->left = curr;
				newNode->right = curr->right;
				curr->right = newNode;
				curr->rightLinkType = CHILD;
				return;
			}
			else {
				curr = curr->right;
			}
		}
		else {

			delete newNode;
			return;
		}
	}

} // end-add

///-----------------------------------------------
/// Removes a given key from the BST (if it exists)
/// 
void ThreadedBST::remove(int key) {
	// Fill this in
	if (root == nullptr) {
		//tree is empty nothing to remove
		return;
	}

	BSTNode* current = root;
	BSTNode* parent = nullptr;

	//find the node with the given key
	while (current != nullptr) {
		if (key < current->key) {
			if (current->leftLinkType == CHILD) {
				parent = current;
				current = current->left;
			}
			else {
				//the key is not in the tree
				return;
			}
		}
		else if (key > current->key) {
			if (current->rightLinkType == CHILD) {
				parent = current;
				current = current->right;
			}
			else {
				//the key is not in the tree
				return;
			}
		}
		else {

			break;
		}
	}

	//if node is found
	if (current != nullptr && current->key == key) {


		BSTNode* child = (current->leftLinkType == CHILD) ? current->left : current->right;

		if (current == root) {
			root = child;
		}
		else if (current == parent->left) {
			parent->left = child;
		}
		else {
			parent->right = child;
		}


		if (current->leftLinkType == THREAD && current->rightLinkType == THREAD) {
			BSTNode* predecessor = current->left;
			BSTNode* successor = current->right;

			if (predecessor != nullptr) {
				predecessor->right = successor;
			}

			if (successor != nullptr) {
				successor->left = predecessor;
			}
		}
		else if (current->leftLinkType == CHILD && current->rightLinkType == THREAD) {
			BSTNode* predecessor = current->left;

			if (predecessor != nullptr) {
				predecessor->right = current->right;
			}
		}
		else if (current->leftLinkType == THREAD && current->rightLinkType == CHILD) {
			BSTNode* successor = current->right;

			if (successor != nullptr) {
				successor->left = current->left;
			}
		}

		delete current;
	}
} // end-remove

///-----------------------------------------------
/// Searches a given key in the ThreadedBST
/// Return a pointer to the node that holds the key
/// If the key is not found, return NULL
/// 
BSTNode* ThreadedBST::find(int key) {
	// Fill this in
	BSTNode* curr = root;

	while (curr != NULL) {
		if (key == curr->key) {
			return curr;
		}
		else if (key < curr->key) {
			curr = (curr->leftLinkType == CHILD) ? curr->left : NULL;
		}
		else {
			curr = (curr->rightLinkType == CHILD) ? curr->right : NULL;
		}
	}

	return NULL;
} // end-find

///-----------------------------------------------
/// Returns the minimum key in the ThreadedBST
/// Return a pointer to the node that holds the key
/// If the key is not found, return NULL
/// 
BSTNode* ThreadedBST::min() {
	// Fill this in
	BSTNode* current = root;
	while (current != nullptr && current->leftLinkType == CHILD) {
		current = current->left;
	}
	return current;
} // end-min

///-----------------------------------------------
/// Returns the maximum key in the ThreadedBST
/// Return a pointer to the node that holds the key
/// If the key is not found, return NULL
/// 
BSTNode* ThreadedBST::max() {
	// Fill this in

	BSTNode* current = root;
	while (current != nullptr && current->rightLinkType == CHILD) {
		current = current->right;
	}
	return current;
} // end-max

///-----------------------------------------------
/// Given a valid pointer to a node in ThreadedBST,
/// returns a pointer to the node that contains the inorder predecessor
/// If the inorder predecessor does not exist, returns NULL
/// 
BSTNode* ThreadedBST::previous(BSTNode* node) {
	// Fill this in
	if (node->leftLinkType == CHILD) {
		// If the left link is a child, find the maximum node in the left subtree
		node = node->left;
		while (node->rightLinkType == CHILD) {
			node = node->right;
		}
		return node;
	}
	else {
		// If the left link is a thread, follow the thread to the in-order predecessor
		return node->left;
	}
} // end-previous

///-----------------------------------------------
/// Given a valid pointer to a node in the ThreadedBST,
/// returns a pointer to the node that contains the inorder successor
/// If the inorder successor does not exist, returns NULL
/// 
BSTNode* ThreadedBST::next(BSTNode* node) {
	if (node->rightLinkType == CHILD) {
		// If the right link is a child, find the minimum node in the right subtree
		node = node->right;
		while (node->leftLinkType == CHILD) {
			node = node->left;
		}
		return node;
	}
	else {
		// If the right link is a thread, follow the thread to the in-order successor
		return node->right;
	}
}
// end-next