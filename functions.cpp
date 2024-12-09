#include "functions.hpp"
#include <vector>

RiverTree::Node*& RiverTree::getHeadPtr() {
    return headPtr;
}

RiverTree::Node* RiverTree::search(Node* node, const string& name) {
    /* if (node == nullptr || node->name == name) {
        return node;
    }

    // Search left and right subtrees
    Node* found = search(node->left_child, name);
    if (found == nullptr) {
        found = search(node->right_child, name);
    }
    return found; */

    if (node == nullptr) {
        return node;
    }

    if (node->left_child && node->left_child->name == name) {
        node = search(node->left_child, name);
        return node;
    } else if (node->right_child && node->right_child->name == name) {
        node = search(node->right_child, name);
        return node;
    } else {
        return node;
    }
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

    // cout << "Inserting node: " << label << " with type " << type << endl;

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

void RiverTree::traverse() {
    traverseHelper(headPtr);
}

void RiverTree::traverseHelper(Node* node) {
    if (node == nullptr) return;

    std::cout << node->name << std::endl;  // Process current node

    char choice;
    cout << "Countinue down river? (y/n) ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        traverseHelper(node->left_child);  // Visit left subtree
        traverseHelper(node->right_child);  // Visit right subtree
    }
    return;
}


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
            cout << "Type: Columbia, Data: " << columbiaNode->data << endl;
            break;
        }
        case 1: { // Tributary = 1
            Tributary* tributaryNode = static_cast<Tributary*>(node);
            cout << "Type: Tributary, Length: " << tributaryNode->length
                 << ", Basin Size: " << tributaryNode->basin_size
                 << ", Average Discharge: " << tributaryNode->average_discharge << endl;
            break;
        }
        case 2: { // Dam = 2
            Dam* damNode = static_cast<Dam*>(node);
            cout << "Type: Dam, Height: " << damNode->height
                 << ", Capacity: " << damNode->capacity << endl;
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

void insertAllData(RiverTree& columbia) {
    std::vector<std::tuple<std::string, int, std::string, std::vector<double>, bool>> riverData = {
        {"Columbia", 1, "Youngs", {43, 257.6, 14.7}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 1, "Grays", {48, 320, 15.9}, true},
        {"Columbia", 0, "Columbia", {0}, false},
        {"Columbia", 1, "Elochoman", {24, 490, 10.8}, true},
        {"Columbia", 0, "Columbia", {0}, false},
        {"Columbia", 1, "Clatskanie", {40, 269.2, 10.6}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 1, "Cowlitz", {169, 6698, 286.6}, true},
        {"Columbia", 0, "Columbia", {0}, false},
        {"Columbia", 1, "Kalama", {72, 530, 34.5}, true},
        {"Columbia", 0, "Columbia", {0}, false},
        {"Columbia", 1, "Lewis", {153, 2709, 173.4}, true},
        {"Columbia", 0, "Columbia", {0}, false},
        {"Columbia", 1, "Lake", {18, 260, 0.0}, true},
        {"Columbia", 0, "Columbia", {0}, false},
        {"Columbia", 1, "Willamette", {301, 28949, 1098.7}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 1, "Washougal", {53, 550, 24.7}, true},
        {"Columbia", 0, "Columbia", {0}, false},
        {"Columbia", 1, "Sandy", {92, 1316, 65.0}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 1, "Wind", {48, 580, 34.2}, true},
        {"Columbia", 0, "Columbia", {0}, false},
        {"Columbia", 1, "Little White Salmon", {31, 350, 0.0}, true},
        {"Columbia", 0, "Columbia", {0}, false},
        {"Columbia", 1, "White Salmon", {71.3, 1000, 30.4}, true},
        {"Columbia", 0, "Columbia", {0}, false},
        {"Columbia", 1, "Hood", {40, 720, 27.6}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 1, "Klickitat", {154.3, 3496, 44.5}, true},
        {"Columbia", 0, "Columbia", {0}, false},
        {"Columbia", 1, "Fifteenmile Creek", {87, 970, 5.6}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 1, "Deschutes", {406, 27549.6, 215.7}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 1, "John Day", {457, 20521.3, 80.4}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 1, "Willow Creek", {127, 2300, 0.9}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 1, "Umatilla", {143, 6345, 14.0}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 1, "Walla Walla", {98, 4553, 34.3}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 1, "Snake", {1735, 260938.7, 1755.6}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 1, "Yakima", {344, 15930.4, 100.3}, true},
        {"Columbia", 0, "Columbia", {0}, false},
        {"Columbia", 1, "Crab Creek", {262, 13200, 40.4}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 1, "Wenatchee", {85, 3473.1, 103.7}, true},
        {"Columbia", 0, "Columbia", {0}, false},
        {"Columbia", 1, "Entiat", {92, 1210, 20.2}, true},
        {"Columbia", 0, "Columbia", {0}, false},
        {"Columbia", 1, "Chelan", {6.6, 2390, 57.8}, true},
        {"Columbia", 0, "Columbia", {0}, false},
        {"Columbia", 1, "Methow", {129, 4727, 44.4}, true},
        {"Columbia", 0, "Columbia", {0}, false},
        {"Columbia", 1, "Okanogan", {185, 21385.7, 99.0}, true},
        {"Columbia", 0, "Columbia", {0}, false},
        {"Columbia", 1, "Nespelem", {0.0, 580.8, 2.5}, true},
        {"Columbia", 0, "Columbia", {0}, false},
        {"Columbia", 1, "Sanpoil", {95, 2540, 11.4}, true},
        {"Columbia", 0, "Columbia", {0}, false},
        {"Columbia", 1, "Spokane", {179, 17353.4, 228.6}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 1, "Colville", {97, 2646.8, 16.4}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 1, "Kettle", {282, 10877, 82.3}, true},
        {"Columbia", 0, "Columbia", {0}, false},
        {"Columbia", 1, "Pend Oreille", {771, 67055.5, 850.2}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 1, "Kootenay", {780, 50298, 868.0}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 1, "Whatshan", {0.0, 581.4, 12.0}, true},
        {"Columbia", 0, "Columbia", {0}, false},
        {"Columbia", 1, "Mosquito Creek", {0.0, 435, 10.2}, true},
        {"Columbia", 0, "Columbia", {0}, false},
        {"Columbia", 1, "Kuskanax Creek", {0.0, 350.9, 10.6}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 1, "Halfway", {0.0, 447.4, 14.2}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 1, "Incomappleux", {0.0, 1020, 55.8}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 1, "Akolkolex", {0.0, 388.7, 16.5}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 1, "Illecillewaet", {62, 1213.3, 61.4}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 1, "Jordan", {0.0, 345.6, 11.1}, true},
        {"Columbia", 0, "Columbia", {0}, false},
        {"Columbia", 1, "Downie Creek", {0.0, 655.8, 27.9}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 1, "Goldstream", {0.0, 954.4, 39.5}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 1, "Big Mouth Creek", {0.0, 591.2, 22.9}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 1, "Canoe", {0.0, 712.6, 15.2}, true},
        {"Columbia", 0, "Columbia", {0}, false},
        {"Columbia", 1, "Wood", {0.0, 841.7, 18.1}, true},
        {"Columbia", 0, "Columbia", {0}, false},
        {"Columbia", 1, "Cummins", {0.0, 262.6, 8.5}, true},
        {"Columbia", 0, "Columbia", {0}, false},
        {"Columbia", 1, "Kinbasket", {0.0, 261.3, 7.6}, true},
        {"Columbia", 0, "Columbia", {0}, false},
        {"Columbia", 1, "Windy", {0.0, 252.3, 10.2}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 1, "Sullivan", {0.0, 632.5, 18.9}, true},
        {"Columbia", 0, "Columbia", {0}, false},
        {"Columbia", 1, "Bush", {0.0, 1100.1, 25.5}, true},
        {"Columbia", 0, "Columbia", {0}, false},
        {"Columbia", 1, "Gold", {0.0, 566.4, 27.9}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 1, "Beaver", {0.0, 1163, 54.3}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 1, "Bluewater", {0.0, 392.5, 12.5}, true},
        {"Columbia", 0, "Columbia", {0}, false},
        {"Columbia", 1, "Waitabit Creek", {0.0, 352.2, 9.6}, true},
        {"Columbia", 0, "Columbia", {0}, false},
        {"Columbia", 1, "Blaeberry", {60, 745.6, 17.8}, true},
        {"Columbia", 0, "Columbia", {0}, false},
        {"Columbia", 1, "Kicking Horse", {0.0, 1815.4, 40.9}, true},
        {"Columbia", 0, "Columbia", {0}, false},
        {"Columbia", 1, "Canyon Creek", {0.0, 161.7, 4.9}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 1, "Spillimacheen", {118, 1456.2, 38.0}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 1, "Bugaboo Creek", {0.0, 368.4, 7.3}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 1, "Forster Creek", {0.0, 592.4, 8.8}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 1, "Horsethief Creek", {0.0, 630.5, 10.0}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 1, "Toby Creek", {0.0, 673.5, 9.0}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 1, "Dutch Creek", {0.0, 676.5, 7.9}, false},
        {"Columbia", 0, "Columbia", {0}, true},
        {"Columbia", 2, "Mica Dam", {240, 2805}, true},
        {"Columbia", 2, "Revelstoke Dam", {175, 2480}, true},
        {"Columbia", 2, "Keenleyside Dam", {52, 185}, true},
        {"Columbia", 2, "Grand Coulee Dam", {170, 6809}, true},
        {"Columbia", 2, "Chief Joseph Dam", {72, 2620}, true},
        {"Columbia", 2, "Wells Dam", {49, 840}, true},
        {"Columbia", 2, "Rocky Reach Dam", {40, 1287}, true},
        {"Columbia", 2, "Rock Island Dam", {41,660}, true},
        {"Columbia", 2, "Wanapum Dam", {56, 1092}, true},
        {"Columbia", 2, "Priest Rapids Dam", {54, 955.6}, true},
        {"Columbia", 2, "McNary Dam", {56, 1133}, true},
        {"Columbia", 2, "John Day Dam", {56, 2485}, true},
        {"Columbia", 2, "The Dalles Dam", {79,2038}, true},
        {"Columbia", 2, "Bonneville Dam", {60, 1190}, true}
    };

    for (size_t i = 0; i < riverData.size(); ++i) {
        string parent = get<0>(riverData[i]);
        int type = get<1>(riverData[i]);
        string label = get<2>(riverData[i]);
        vector<double> data = get<3>(riverData[i]);
        bool asLeft = get<4>(riverData[i]);

        columbia.insertByName(parent, type, label, data, asLeft);
    }
}