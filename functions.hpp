#include <iostream>
#include <string>
using namespace std;

class RiverTree {
private:
    struct Tributary {
        string name;
        double length;
        Tributary* left_child;
        Tributary* right_child;

        struct Dam {
            string name;
            int capacity;
            Dam* nextPtr;
        };
        
        Dam* headPtr;
    };

    Tributary* headPtr;

    
public:
    RiverTree() {
        headPtr = nullptr;
    
    };

    void insert(Tributary trib);

    void traverse();

    void printAll();

    void subPrint(string name);

    void del(string name);
};