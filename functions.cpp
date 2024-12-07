#include "functions.hpp"

RiverTree::Node *RiverTree::getHeadPtr() {
    return headPtr;
}

void RiverTree::insert(Node* child, int type, string label, double data) {
    // Create a new node based on the type
    Node* newNode = nullptr;
    if (type == 0) {
        Columbia* columbiaNode = new Columbia();
        columbiaNode->data = data;
        newNode = columbiaNode;
    } else if (type == 1) {
        Tributary* tributaryNode = new Tributary();
        tributaryNode->length = data;
        newNode = tributaryNode;
    } else if (type == 2) {
        Dam* damNode = new Dam();
        damNode->height = data;
        newNode = damNode;
    }

    // Set the common attributes for the new node
    newNode->name = label;
    newNode->left_child = nullptr;
    newNode->right_child = nullptr;

    // If the tree is empty, set the new node as the head
    if (headPtr == nullptr) {
        headPtr = newNode;
        return;
    }

    // Traverse the tree to find the insertion point
    Node* current = headPtr;
    Node* parent = nullptr;

    while (current != nullptr) {
        parent = current;

        if (label < current->name) {
            current = current->left_child;
        } else {
            current = current->right_child;
        }
    }

    // Use the `child` parameter to determine the direction of insertion
    if (child == parent->left_child) {
        parent->left_child = newNode;
    } else if (child == parent->right_child) {
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
    printAllHelper(headPtr); // Start from the root node
}

void RiverTree::printAllHelper(Node* node) {
    if (node == nullptr) {
        return; // Base case: stop if the node is null
    }

    // Print the common node details
    cout << "Name: " << node->name << endl;

    // Use the `type` field to determine the type of the node and print details
    switch (node->type) {
        case 0: { // Columbia
            Columbia* columbiaNode = static_cast<Columbia*>(node);
            cout << "Type: Columbia, Data: " << columbiaNode->data << endl;
            break;
        }
        case 1: { // Tributary
            Tributary* tributaryNode = static_cast<Tributary*>(node);
            cout << "Type: Tributary, Length: " << tributaryNode->length
                 << ", Basin Size: " << tributaryNode->basin_size
                 << ", Average Discharge: " << tributaryNode->average_discharge << endl;
            break;
        }
        case 2: { // Dam
            Dam* damNode = static_cast<Dam*>(node);
            cout << "Type: Dam, Height: " << damNode->height
                 << ", Capacity: " << damNode->capacity << endl;
            break;
        }
        default:
            cout << "Unknown node type!" << endl;
    }

    // Recursively print left and right subtrees
    printAllHelper(node->left_child);  // Traverse left
    printAllHelper(node->right_child); // Traverse right
}


void RiverTree::subPrint(string name) {
    Node* target = nullptr; // variable for target node
    subPrintHelper(headPtr, name, target);
    if (target) {
        printAllHelper(target);
    } else {
        cout << "The target node was not found within the tree" << endl;
    }
}

void RiverTree::subPrintHelper(Node* root, string& name, Node*& target) {
    if (root == nullptr || target != nullptr) {
        return; // stops when target is found
    }

    if (root->name == name) {
        target = root; // node has been found
        return;
    }

    // Recursively search in the left and right subtrees
    subPrintHelper(root->left_child, name, target);
    subPrintHelper(root->right_child, name, target);
}

// find target node using subPrintHelper
void RiverTree::del(string name) {
Node* target = nullptr; // variable for target node to delete 
subPrintHelper(headPtr, name, target);
if (target == nullptr) {
    cout << "The target node was not found within the tree" << endl;
} else {
// delete node
}


}

