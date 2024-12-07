#include "functions.hpp"

int main() {
    RiverTree columbia;
    columbia.insert(columbia.getHeadPtr(), 0, "Columbia", {0.0});
    columbia.insertByName("Columbia", 1, "Youngs", {43, 257.6, 14.7}, true);
    columbia.insertByName("Columbia", 1, "Grays", {48, 320, 15.9}, false);
    columbia.insertByName("Columbia", 1, "Elochoman", {24, 490, 10.8}, false);
    columbia.insertByName("Columbia", 1, "Clatskanie", {40, 269.2, 10.6}, false);
    columbia.insertByName("Columbia", 1, "Cowlitz", {169, 6698, 286.6}, true);
    columbia.insertByName("Columbia", 1, "Kalama", {72, 530, 34.5}, false);
    columbia.insertByName("Columbia", 1, "Lewis", {153, 2709, 173.4}, false);
    columbia.insertByName("Columbia", 1, "Lake", {18, 260, 0.0}, false);
    columbia.insertByName("Columbia", 1, "Willamette", {301, 28949, 1098.7}, true);
    columbia.insertByName("Columbia", 1, "Washougal", {53, 550, 24.7}, false);
    columbia.insertByName("Columbia", 1, "Sandy", {92, 1316, 65.0}, false);
    columbia.insertByName("Columbia", 1, "Wind", {48, 580, 34.2}, false);
    columbia.insertByName("Columbia", 1, "Little White Salmon", {31, 350, 0.0}, false);
    columbia.insertByName("Columbia", 1, "White Salmon", {71.3, 1000, 30.4}, false);
    columbia.insertByName("Columbia", 1, "Hood", {40, 720, 27.6}, false);
    columbia.insertByName("Columbia", 1, "Klickitat", {154.3, 3496, 44.5}, false);
    columbia.insertByName("Columbia", 1, "Fifteenmile Creek", {87, 970, 5.6}, false);
    columbia.insertByName("Columbia", 1, "Deschutes", {406, 27549.6, 215.7}, false);
    columbia.insertByName("Columbia", 1, "John Day", {457, 20521.3, 80.4}, false);
    columbia.insertByName("Columbia", 1, "Willow Creek", {127, 2300, 0.9}, false);
    columbia.insertByName("Columbia", 1, "Umatilla", {143, 6345, 14.0}, false);
    columbia.insertByName("Columbia", 1, "Walla Walla", {98, 4553, 34.3}, false);
    columbia.insertByName("Columbia", 1, "Snake", {1735, 260938.7, 1755.6}, true);
    columbia.insertByName("Columbia", 1, "Yakima", {344, 15930.4, 100.3}, true);
    columbia.insertByName("Columbia", 1, "Crab Creek", {262, 13200, 40.4}, false);
    columbia.insertByName("Columbia", 1, "Wenatchee", {85, 3473.1, 103.7}, false);
    columbia.insertByName("Columbia", 1, "Entiat", {92, 1210, 20.2}, false);
    columbia.insertByName("Columbia", 1, "Chelan", {6.6, 2390, 57.8}, false);
    columbia.insertByName("Columbia", 1, "Methow", {129, 4727, 44.4}, false);
    columbia.insertByName("Columbia", 1, "Okanogan", {185, 21385.7, 99.0}, false);
    columbia.insertByName("Columbia", 1, "Nespelem", {0.0, 580.8, 2.5}, false);
    columbia.insertByName("Columbia", 1, "Sanpoil", {95, 2540, 11.4}, false);
    columbia.insertByName("Columbia", 1, "Spokane", {179, 17353.4, 228.6}, false);
    columbia.insertByName("Columbia", 1, "Colville", {97, 2646.8, 16.4}, false);
    columbia.insertByName("Columbia", 1, "Kettle", {282, 10877, 82.3}, false);
    columbia.insertByName("Columbia", 1, "Pend Oreille", {771, 67055.5, 850.2}, true);
    columbia.insertByName("Columbia", 1, "Kootenay", {780, 50298, 868.0}, false);
    columbia.insertByName("Columbia", 1, "Whatshan", {0.0, 581.4, 12.0}, false);
    columbia.insertByName("Columbia", 1, "Mosquito Creek", {0.0, 435, 10.2}, false);
    columbia.insertByName("Columbia", 1, "Kuskanax Creek", {0.0, 350.9, 10.6}, false);
    columbia.insertByName("Columbia", 1, "Halfway", {0.0, 447.4, 14.2}, false);
    columbia.insertByName("Columbia", 1, "Incomappleux", {0.0, 1020, 55.8}, false);
    columbia.insertByName("Columbia", 1, "Akolkolex", {0.0, 388.7, 16.5}, false);
    columbia.insertByName("Columbia", 1, "Illecillewaet", {62, 1213.3, 61.4}, false);
    columbia.insertByName("Columbia", 1, "Jordan", {0.0, 345.6, 11.1}, false);
    columbia.insertByName("Columbia", 1, "Downie Creek", {0.0, 655.8, 27.9}, false);
    columbia.insertByName("Columbia", 1, "Goldstream", {0.0, 954.4, 39.5}, false);
    columbia.insertByName("Columbia", 1, "Big Mouth Creek", {0.0, 591.2, 22.9}, false);
    columbia.insertByName("Columbia", 1, "Canoe", {0.0, 712.6, 15.2}, false);
    columbia.insertByName("Columbia", 1, "Wood", {0.0, 841.7, 18.1}, false);
    columbia.insertByName("Columbia", 1, "Cummins", {0.0, 262.6, 8.5}, false);
    columbia.insertByName("Columbia", 1, "Kinbasket", {0.0, 261.3, 7.6}, false);
    columbia.insertByName("Columbia", 1, "Windy", {0.0, 252.3, 10.2}, false);
    columbia.insertByName("Columbia", 1, "Sullivan", {0.0, 632.5, 18.9}, false);
    columbia.insertByName("Columbia", 1, "Bush", {0.0, 1100.1, 25.5}, false);
    columbia.insertByName("Columbia", 1, "Gold", {0.0, 566.4, 27.9}, false);
    columbia.insertByName("Columbia", 1, "Beaver", {0.0, 1163, 54.3}, false);
    columbia.insertByName("Columbia", 1, "Bluewater", {0.0, 392.5, 12.5}, false);
    columbia.insertByName("Columbia", 1, "Waitabit Creek", {0.0, 352.2, 9.6}, false);
    columbia.insertByName("Columbia", 1, "Blaeberry", {60, 745.6, 17.8}, false);
    columbia.insertByName("Columbia", 1, "Kicking Horse", {0.0, 1815.4, 40.9}, false);
    columbia.insertByName("Columbia", 1, "Canyon Creek", {0.0, 161.7, 4.9}, false);
    columbia.insertByName("Columbia", 1, "Spillimacheen", {118, 1456.2, 38.0}, false);
    columbia.insertByName("Columbia", 1, "Bugaboo Creek", {0.0, 368.4, 7.3}, false);
    columbia.insertByName("Columbia", 1, "Forster Creek", {0.0, 592.4, 8.8}, false);
    columbia.insertByName("Columbia", 1, "Horsethief Creek", {0.0, 630.5, 10.0}, false);
    columbia.insertByName("Columbia", 1, "Toby Creek", {0.0, 673.5, 9.0}, false);
    columbia.insertByName("Columbia", 1, "Dutch Creek", {0.0, 676.5, 7.9}, false);

    // river.insert(river.getHeadPtr()->right_child, 2, "Dam B", 78.0);
    // river.insert(river.getHeadPtr()->left_child, 1, "Tributary A", 45.6);

    columbia.printAll(); 
    // insertAllData(river);
}

void insertAllData(RiverTree river) {

}