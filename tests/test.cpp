#include <stdio.h>
#include <stdlib.h>
#include "../solutions/solution.c"  // Include the solution file

// Helper function to build the linked list
struct ListNode* buildList(int values[], int size, struct ListNode** target, int targetVal) {
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = values[0];
    head->next = NULL;
    struct ListNode* curr = head;
    if (values[0] == targetVal) *target = curr;

    for (int i = 1; i < size; ++i) {
        curr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        curr = curr->next;
        curr->val = values[i];
        curr->next = NULL;
        if (values[i] == targetVal) *target = curr;
    }
    return head;
}

// Helper function to print the linked list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// Function to compare two lists
int compareLists(struct ListNode* head1, int expected[], int size) {
    int i = 0;
    while (head1 && i < size) {
        if (head1->val != expected[i]) {
            return 0;  // Lists do not match
        }
        head1 = head1->next;
        i++;
    }
    return i == size && head1 == NULL;  // Check if both lists are fully traversed
}

// Function to run the test case
void runTestCase(int input[], int size, int nodeToDelete, int expected[], int expected_size) {
    struct ListNode* node = NULL;
    struct ListNode* head = buildList(input, size, &node, nodeToDelete);
    deleteNode(node);

    if (compareLists(head, expected, expected_size)) {
        printf("✅ Test Passed\n");
    } else {
        printf("❌ Test Failed\nExpected: ");
        for (int i = 0; i < expected_size; i++) {
            printf("%d ", expected[i]);
        }
        printf("\nGot: ");
        printList(head);
    }
}

// Main function to run multiple test cases
int main() {
    int passed = 0, total = 0;

    // Test cases
    int input1[] = {4, 5, 1, 9};
    int expected1[] = {4, 1, 9};
    runTestCase(input1, 4, 5, expected1, 3);
    total++;

    int input2[] = {4, 5, 1, 9};
    int expected2[] = {4, 5, 9};
    runTestCase(input2, 4, 1, expected2, 3);
    total++;

    int input3[] = {1, 2};
    int expected3[] = {2};
    runTestCase(input3, 2, 1, expected3, 1);
    total++;

    int input4[] = {1, 2, 3, 4};
    int expected4[] = {1, 2, 4};
    runTestCase(input4, 4, 3, expected4, 3);
    total++;

    int input5[] = {10, 20, 30, 40, 50};
    int expected5[] = {10, 20, 40, 50};
    runTestCase(input5, 5, 30, expected5, 4);
    total++;

    int input6[] = {1, 100, 1000};
    int expected6[] = {1, 1000};
    runTestCase(input6, 3, 100, expected6, 2);
    total++;

    int input7[] = {0, -1, -2, -3};
    int expected7[] = {0, -1, -3};
    runTestCase(input7, 4, -2, expected7, 3);
    total++;

    int input8[] = {1000, 2000, 3000, 4000};
    int expected8[] = {1000, 2000, 4000};
    runTestCase(input8, 4, 3000, expected8, 3);
    total++;

    int input9[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int expected9[] = {1, 2, 3, 4, 5, 7, 8, 9, 10};
    runTestCase(input9, 10, 6, expected9, 9);
    total++;

    int largeInput[1000];
    for (int i = 0; i < 1000; i++) largeInput[i] = 1;
    largeInput[500] = 2;  // Node to delete is 2
    int largeExpected[999];
    for (int i = 0; i < 999; i++) largeExpected[i] = 1;
    runTestCase(largeInput, 1000, 2, largeExpected, 999);
    total++;

    printf("\n\nPassed %d / %d test cases.\n", passed, total);
    return 0;
}
