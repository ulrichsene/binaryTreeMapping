#include <iostream>
#include <string>
#include <vector>

using namespace std;

class RiverTree {
private:
    struct Node {
        int type;
        string name;
        Node* left_child;
        Node* right_child;

        double data1;
        double data2;
        double data3;
    };

    struct Tributary : public Node {
        double length;
        double basin_size;
        double average_discharge;
    };
    
    struct Dam : public Node {
        double height;
        double capacity;
    };

    struct Columbia : public Node {
        double data;
    };

    Node* search(Node* node, const string& name);
    Node* searchDamParent(Node* node, const string& name);

    Node* descendTrib(Node* node);

    Node* headPtr;

public:
    
    RiverTree() {
        headPtr = nullptr;
    };

    Node*& getHeadPtr();

    void insert(Node* parent, bool isLeftChild, int type, string label, vector<double> data);
    void insertByName(const string& parentName, int type, const string& label, const vector<double>& data, bool isLeft);

    void traverse();
    void traverseHelper(Node* node);

    void printAll();
    void printAllHelper(Node* node, Node* parent);

    void subPrint(string name);
    void subPrintHelper(Node* root, string& name, Node*& target);

    void del(string name);
};

void insertAllData(RiverTree& columbia);