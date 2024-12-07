#include <iostream>
#include <string>
using namespace std;

class RiverTree {
public:
    struct Node {
        int type;
        string name;
        Node* left_child;
        Node* right_child;
    };

    struct Tributary : public Node {
        double length;
        double basin_size;
        double average_discharge;
    };
    
    struct Dam : public Node {
        double height;
        int capacity;
    };

    struct Columbia : public Node {
        double data;
    };

    Node* headPtr;
    
    RiverTree() {
        headPtr = nullptr;
    };

    Node* getHeadPtr();

    void insert(Node* child, int type, string label, double data);

    void traverse();
    void traverseHelper(Node* node);

    void printAll();
    void printAllHelper(Node* node);

    void subPrint(string name);
    void subPrintHelper(Node* root, string& name, Node*& target);

    void del(string name);
};