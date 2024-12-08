#include "functions.hpp"

void insertAllData(RiverTree& river);

int main() {
    RiverTree columbia;

    // Initialize the head of Columbia
    columbia.insert(columbia.getHeadPtr(), true, 0, "Columbia", {0.0});

    // Insert all river data
    insertAllData(columbia);

    int choice;
    bool run = true;
    string name;

    while (run) {
        cout << "\nChoose from the following:\n\n";
        cout << "1) Print entire river.\n";
        cout << "2) Explore river node by node\n";
        cout << "3) Find a specific node\n";
        cout << "4) Quit program\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                columbia.printAll();
                break;
            case 2:
                break;
            case 3:
                cout << "Enter the name of the river portion you'd like to search for: ";
                cin >> name;
                columbia.subPrint(name);
                break;
            case 4:
                run = false;
                break;
            default:
                cout <<"Invalid input.\n";
                break;
        }
    }

    return 0;
}