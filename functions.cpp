#include "functions.hpp"

void RiverTree::insert(Node node) {
    // Create a new node 
    Node* newNode = new Node();
    *newNode = node;  // Copy data into new node
    newNode->left_child = nullptr;
    newNode->right_child = nullptr;

    // If tree is empty set new node as the head
    if (headPtr == nullptr) {
        headPtr = newNode;
        return;
    }

    // Traverse the tree to find the spot for the new node
    Node* current = headPtr;
    Node* parent = nullptr;

    while (current != nullptr) {
        parent = current;

        if (node.name < current->name) {
            current = current->left_child;
        } else {
            current = current->right_child;
        }
    }

    // Insert the new node as a child of the parent
    if (node.name < parent->name) {
        parent->left_child = newNode;
    } else {
        parent->right_child = newNode;
    }
}

void RiverTree::traverse() {
   traverseHelper(headPtr);
}

void RiverTree::traverseHelper(Node* node) {
   if (node == nullptr) return;


   traverseHelper(node->left_child);  // Visit left subtree
   std::cout << node->name << std::endl;  // Process current node
   traverseHelper(node->right_child);  // Visit right subtree
}


void RiverTree::printAll() {
// bob 
}

void RiverTree::subPrint(string name) {

}

void RiverTree::del(string name) {

}