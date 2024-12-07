#include "functions.hpp"
#include <vector>

RiverTree::Node*& RiverTree::getHeadPtr() {
    return headPtr;
}

RiverTree::Node* RiverTree::search(Node* node, const string& name) {
    if (node == nullptr || node->name == name) {
        return node; // Return if node is found or if tree traversal ends
    }

    // Search left and right subtrees
    Node* found = search(node->left_child, name);
    if (found == nullptr) {
        found = search(node->right_child, name);
    }
    return found;
}

void RiverTree::insert(Node* child, int type, string label, const vector<double>& data) {
    Node* newNode = nullptr;

    if (type == 0) { // Columbia
        Columbia* columbiaNode = new Columbia();
        columbiaNode->data = data[0];
        columbiaNode->type = 0;  // Set the type explicitly
        newNode = columbiaNode;
    } else if (type == 1) { // Tributary
        Tributary* tributaryNode = new Tributary();
        tributaryNode->length = data[0];
        tributaryNode->basin_size = data[1];
        tributaryNode->average_discharge = data[2];
        tributaryNode->type = 1;  // Set the type explicitly
        newNode = tributaryNode;
    } else if (type == 2) { // Dam
        Dam* damNode = new Dam();
        damNode->height = data[0];
        damNode->capacity = static_cast<int>(data[1]);
        damNode->type = 2;  // Set the type explicitly
        newNode = damNode;
    }

    newNode->name = label;
    newNode->left_child = nullptr;
    newNode->right_child = nullptr;

    // Insertion logic remains unchanged...
    if (headPtr == nullptr) {
        headPtr = newNode;
        return;
    }

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

    if (child == parent->left_child) {
        parent->left_child = newNode;
    } else if (child == parent->right_child) {
        parent->right_child = newNode;
    }
}

void RiverTree::insertByName(const string& parentName, int type, const string& label, const vector<double>& data, bool asLeft) {
    Node* parent = search(headPtr, parentName);
    if (parent == nullptr) {
        cout << "Parent node not found!" << endl;
        return;
    }

    if (asLeft) {
        insert(parent->left_child, type, label, data);
    } else {
        insert(parent->right_child, type, label, data);
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
        return;
    }

    cout << "Name: " << node->name << endl;

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

    printAllHelper(node->left_child);
    printAllHelper(node->right_child);
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

