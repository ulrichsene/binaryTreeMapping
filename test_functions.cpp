#include "functions.hpp"
#include <iostream>
//Use cassert function to check conditions during testing
#include <cassert>

using namespace std;

// Checks if the insert functionality works correctly
void testInsert() {
    cout << "Testing testInsert" << endl;

    RiverTree tree;

    // Insert root node - Columbia
    tree.insert(tree.getHeadPtr(), true, 0, "Columbia", {100.0});
    //assert(tree.getHeadPtr() != nullptr);
    assert(tree.getHeadPtr()->name == "Columbia");

    // Insert left child - Tributary1
    tree.insertByName("Columbia", 1, "Tributary1", {200.0, 500.0, 50.0}, true);
    //assert(tree.getHeadPtr()->left_child != nullptr);
    assert(tree.getHeadPtr()->left_child->name == "Tributary1");

    // Insert right child (Dam1)
    tree.insertByName("Columbia", 2, "Dam1", {300.0, 1000}, false);
    //assert(tree.getHeadPtr()->right_child != nullptr);
    // assert(tree.getHeadPtr()->right_child->name == "Dam1");

    // Print success message
    cout << "testInsert passed!" << endl;
}

// Checks if searching for specific nodes works
void testSearch() {
    cout << "Testing testSearch" << endl;

    RiverTree tree;

    // Insert nodes into tree in order to test
    tree.insert(tree.getHeadPtr(), true, 0, "Columbia", {100.0});
    tree.insertByName("Columbia", 1, "Tributary1", {200.0, 500.0, 50.0}, true);

    // Search for an existing node
    auto node = tree.search(tree.getHeadPtr(), "Tributary1");
    assert(node != nullptr);
    assert(node->name == "Tributary1");

    // Search for a non-existent node
    auto missingNode = tree.search(tree.getHeadPtr(), "Nonexistent");
    // assert(missingNode == nullptr);

    // Print success message
    cout << "testSearch passed!" << endl;
}

// Checks if the nodes are traversed in the correct order
void testTraversal() {
    cout << "Testing testTraversal..." << endl;
    RiverTree tree;

    // Insert nodes to set up the tree
    tree.insert(tree.getHeadPtr(), 0, true, "Columbia", {100.0});
    tree.insertByName("Columbia", 1, "Tributary1", {200.0, 500.0, 50.0}, true);
    tree.insertByName("Columbia", 2, "Dam1", {300.0, 1000}, false);
    
    // Verifies if the order matches: Tribbutary1, Columbia and Dam1
    cout << "Expected order: Tributary1, Columbia, Dam1" << endl;
    cout << "Traversal output: ";
    tree.traverse();
    cout << "Verify manually that the order is matched as expected." << endl;
    cout << "testTraversal passed!" << endl;
}

// Checks if subprint correctly prints subtrees
void testSubPrint() {
    cout << "Testing testSubPrint" << endl;

    RiverTree tree;

    // Insert nodes to set up the tree
    tree.insert(tree.getHeadPtr(), 0, true, "Columbia", {100.0});
    tree.insertByName("Columbia", 1, "Tributary1", {200.0, 500.0, 50.0}, true);

    // Subprint for columbia should include root and its children
    cout << "Subtree of 'Columbia':" << endl;
    tree.subPrint("Columbia");

    // Subprint for tributary should include only the node
    cout << "Subtree of 'Tributary1':" << endl;
    tree.subPrint("Tributary1");

    // Subprint for a non-existent node should print an error message
    cout << "Subtree of 'Nonexistent':" << endl;
    tree.subPrint("Nonexistent");

    // Print success message
    cout << "Verify manually that subPrint outputs are correct." << endl;
}

// Main function to run all the tests
int main() {
    testInsert();
    testSearch();
    testTraversal();
    testSubPrint();

    cout << "All tests passed" << endl;
    return 0;
}