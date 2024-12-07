#include "functions.hpp"

int main() {
    RiverTree columbia;
    columbia.insert(columbia.getHeadPtr(), 0, "Columbia", {0.0});
    columbia.insertByName("Columbia",1,"Cowlitz",{169, 6698, 286.6}, true);

    // river.insert(river.getHeadPtr()->right_child, 2, "Dam B", 78.0);
    // river.insert(river.getHeadPtr()->left_child, 1, "Tributary A", 45.6);

    columbia.printAll(); 
    // insertAllData(river);
}

void insertAllData(RiverTree river) {

}