#include <iostream>
#include <string>
using namespace std;

class RiverTree {
private:
    struct Node {
        string name;
        Node* left_child;
        Node* right_child;
    };

    struct Tributary : Node {
        double length;
        double basin_size;
        double average_discharge;
    };
    
    struct Dam : Node {
        int height;
        int capacity;
    };

    Node* headPtr;
    
public:
    RiverTree() {
        headPtr = nullptr;
    };

    void insert(Node node);

    void traverse();

    void printAll();

    void subPrint(string name);

    void del(string name);
};