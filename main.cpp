#include "functions.hpp"

int main() {
    RiverTree river;
    river.insert(nullptr, 0, "Columbia", 123.0);

    river.insert(river.getHeadPtr()->right_child, 2, "Dam B", 78.0);
    river.insert(river.getHeadPtr()->left_child, 1, "Tributary A", 45.6);

    river.printAll(); 
    // insertAllData(river);
}

void insertAllData(RiverTree river) {

}