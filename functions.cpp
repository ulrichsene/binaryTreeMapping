#include "functions.hpp"
#include <vector>

RiverTree::Node*& RiverTree::getHeadPtr() {
    return headPtr;
}

RiverTree::Node* RiverTree::search(Node* node, const string& name) {
    if (node == nullptr || node->name == name) {
        return node;
    }

    // Search left and right subtrees
    Node* found = search(node->left_child, name);
    if (found == nullptr) {
        found = search(node->right_child, name);
    }
    return found;
}

void RiverTree::insert(Node* parent, bool isLeftChild, int type, string label, vector<double> data) {
    Node* newNode = nullptr;

    // Create new node based on the type
    if (type == 0) { // columbia = 0
        Columbia* columbiaNode = new Columbia();
        columbiaNode->data = data[0];
        columbiaNode->type = 0;
        newNode = columbiaNode;
    } else if (type == 1) { // Tributary = 1
        Tributary* tributaryNode = new Tributary();
        tributaryNode->length = data[0];
        tributaryNode->basin_size = data[1];
        tributaryNode->average_discharge = data[2];
        tributaryNode->type = 1;
        newNode = tributaryNode;
    } else if (type == 2) { // Dam = 2
        Dam* damNode = new Dam();
        damNode->height = data[0];
        damNode->capacity = data[1];
        damNode->type = 2;
        newNode = damNode;
    }

    // Set attributes
    newNode->name = label;
    newNode->left_child = nullptr;
    newNode->right_child = nullptr;

    cout << "Inserting node: " << label << " with type " << type << endl;

    // If tree is empty, set the new node as headPtr
    if (headPtr == nullptr) {
        headPtr = newNode;
        return;
    }

    // If parent is !nullptr insert new node as child
    if (parent != nullptr) {
        if (isLeftChild) {
            parent->left_child = newNode;
        } else {
            parent->right_child = newNode;
        }
    }
}


void RiverTree::insertByName(const string& parentName, int type, const string& label, const vector<double>& data, bool asLeft) {
    Node* parentNode = search(headPtr, parentName);

    if (parentNode || headPtr == nullptr) {
        insert(parentNode, asLeft, type, label, data);
    } else {
        cout << "Parent node not found: " << parentName << endl;
    }
}

// void RiverTree::traverse() {
//    traverseHelper(headPtr);
// }

// void RiverTree::traverseHelper(Node* node) {
//    if (node == nullptr) return;


//    traverseHelper(node->left_child);  // Visit left subtree
//    std::cout << node->name << std::endl;  // Process current node
//    traverseHelper(node->right_child);  // Visit right subtree
// }


void RiverTree::printAll() {
    printAllHelper(headPtr, nullptr); // Start from the root node
}

void RiverTree::printAllHelper(Node* node, Node* parent) {
    if (node == nullptr) {
        return;
    }

    // Print name
    cout << "Name: " << node->name << endl;

    // Handle data for each type
    switch (node->type) {
        case 0: { // Columbia = 0
            Columbia* columbiaNode = static_cast<Columbia*>(node);
            cout << "Type: Columbia, Data: {" << columbiaNode->data << "}, Root: " 
                 << (parent == nullptr ? "true" : "false") << endl;
            break;
        }
        case 1: { // Tributary = 1
            Tributary* tributaryNode = static_cast<Tributary*>(node);
            cout << "Type: Tributary, Length: " << tributaryNode->length
                 << ", Basin Size: " << tributaryNode->basin_size
                 << ", Average Discharge: " << tributaryNode->average_discharge
                 << ", Root: " << (parent == nullptr ? "true" : "false") << endl;
            break;
        }
        case 2: { // Dam = 2
            Dam* damNode = static_cast<Dam*>(node);
            cout << "Type: Dam, Height: " << damNode->height
                 << ", Capacity: " << damNode->capacity
                 << ", Root: " << (parent == nullptr ? "true" : "false") << endl;
            break;
        }
        default:
            cout << "Unknown node type" << endl;
    }

    // Recursively traverse the tree
    printAllHelper(node->left_child, node);
    printAllHelper(node->right_child, node);
}

void RiverTree::subPrint(string name) {
    Node* target = nullptr; // variable for target node
    subPrintHelper(headPtr, name, target);
    if (target) {
        printAllHelper(target, nullptr);
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
