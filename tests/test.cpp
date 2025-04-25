#include <iostream>
#include <vector>
#include "../solutions/solution.cpp"  // Include the C++ solution file
using namespace std;

// Helper function to build the linked list
ListNode* buildList(vector<int>& values, int size, ListNode** target, int targetVal) {
    ListNode* head = new ListNode(values[0]);
    ListNode* curr = head;
    if (values[0] == targetVal) *target = curr;

    for (int i = 1; i < size; ++i) {
        curr->next = new ListNode(values[i]);
        curr = curr->next;
        if (values[i] == targetVal) *target = curr;
    }
    return head;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to compare two lists
bool compareLists(ListNode* head1, vector<int>& expected) {
    int i = 0;
    while (head1 && i < expected.size()) {
        if (head1->val != expected[i]) {
            return false;  // Lists do not match
        }
        head1 = head1->next;
        i++;
    }
    return i == expected.size() && head1 == nullptr;  // Check if both lists are fully traversed
}

// Function to run the test case
void runTestCase(vector<int> input, int size, int nodeToDelete, vector<int> expected, int *passed) {
    ListNode* node = nullptr;
    ListNode* head = buildList(input, size, &node, nodeToDelete);

    // Instantiate Solution object and call deleteNode on it
    Solution solution;
    solution.deleteNode(node);

    if (compareLists(head, expected)) {
        cout << "Test Passed" << endl;
        (*passed)++;  // Increment passed count
    } else {
        cout << "Test Failed\nExpected: ";
        for (int val : expected) {
            cout << val << " ";
        }
        cout << "\nGot: ";
        printList(head);
    }
}

// Main function to run multiple test cases
int main() {
    int passed = 0, total = 0;

    // Test case 1
    int input1[] = {4, 5, 1, 9};
    int expected1[] = {4, 1, 9};
    runTestCase(vector<int>(input1, input1 + 4), 4, 5, vector<int>(expected1, expected1 + 3), &passed);
    total++;

    // Test case 2
    int input2[] = {4, 5, 1, 9};
    int expected2[] = {4, 5, 9};
    runTestCase(vector<int>(input2, input2 + 4), 4, 1, vector<int>(expected2, expected2 + 3), &passed);
    total++;

    // Test case 3
    int input3[] = {1, 2};
    int expected3[] = {2};
    runTestCase(vector<int>(input3, input3 + 2), 2, 1, vector<int>(expected3, expected3 + 1), &passed);
    total++;

    // Test case 4
    int input4[] = {1, 2, 3, 4};
    int expected4[] = {1, 2, 4};
    runTestCase(vector<int>(input4, input4 + 4), 4, 3, vector<int>(expected4, expected4 + 3), &passed);
    total++;

    // Test case 5
    int input5[] = {10, 20, 30, 40, 50};
    int expected5[] = {10, 20, 40, 50};
    runTestCase(vector<int>(input5, input5 + 5), 5, 30, vector<int>(expected5, expected5 + 4), &passed);
    total++;

    // Test case 6
    int input6[] = {1, 100, 1000};
    int expected6[] = {1, 1000};
    runTestCase(vector<int>(input6, input6 + 3), 3, 100, vector<int>(expected6, expected6 + 2), &passed);
    total++;

    // Test case 7
    int input7[] = {0, -1, -2, -3};
    int expected7[] = {0, -1, -3};
    runTestCase(vector<int>(input7, input7 + 4), 4, -2, vector<int>(expected7, expected7 + 3), &passed);
    total++;

    // Test case 8
    int input8[] = {1000, 2000, 3000, 4000};
    int expected8[] = {1000, 2000, 4000};
    runTestCase(vector<int>(input8, input8 + 4), 4, 3000, vector<int>(expected8, expected8 + 3), &passed);
    total++;

    // Test case 9
    int input9[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int expected9[] = {1, 2, 3, 4, 5, 7, 8, 9, 10};
    runTestCase(vector<int>(input9, input9 + 10), 10, 6, vector<int>(expected9, expected9 + 9), &passed);
    total++;
    
    
    cout << "Total tests executed: " << total << endl;

    // Print final test results
    cout << "\n\nPassed " << passed << " / " << total << " test cases." << endl;
    return 0;
}
