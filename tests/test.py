import sys
import os

# Ensure the parent directory is in the Python path
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))

from solutions.solution import Solution


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

# Helper function to build the linked list
def build_list(values, target_val):
    head = ListNode(values[0])
    current = head
    target = None

    if values[0] == target_val:
        target = current

    for value in values[1:]:
        current.next = ListNode(value)
        current = current.next
        if value == target_val:
            target = current

    return head, target

# Helper function to convert list to Python list for easier comparison
def list_to_array(head):
    result = []
    while head:
        result.append(head.val)
        head = head.next
    return result

# Function to run the test case
def run_test_case(input_list, node_to_delete, expected_result):
    head, node = build_list(input_list, node_to_delete)
    if node:
        solution = Solution()
        solution.deleteNode(node)

    result = list_to_array(head)

    if result == expected_result:
        return True, result
    else:
        return False, result

# Running test cases
def main():
    passed = 0
    total = 0

    # Test Cases
    test_cases = [
        ([4, 5, 1, 9], 5, [4, 1, 9]),
        ([4, 5, 1, 9], 1, [4, 5, 9]),
        ([1, 2], 1, [2]),
        ([1, 2, 3, 4], 3, [1, 2, 4]),
        ([10, 20, 30, 40, 50], 30, [10, 20, 40, 50]),
        ([1, 100, 1000], 100, [1, 1000]),
        ([0, -1, -2, -3], -2, [0, -1, -3]),
        ([1000, 2000, 3000, 4000], 3000, [1000, 2000, 4000]),
        ([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 6, [1, 2, 3, 4, 5, 7, 8, 9, 10]),
    ]

    # Loop through the test cases
    for input_list, node_to_delete, expected_result in test_cases:
        total += 1
        passed_test, result = run_test_case(input_list, node_to_delete, expected_result)
        if passed_test:
            print(f"✅ Test Passed: {input_list} -> {expected_result}")
            passed += 1
        else:
            print(f"❌ Test Failed: {input_list} -> Expected: {expected_result}, Got: {result}")

    print(f"\nPassed {passed} / {total} test cases.")

if __name__ == "__main__":
    main()
