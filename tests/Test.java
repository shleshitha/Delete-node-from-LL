package tests;

import solutions.ListNode;
import solutions.Solution;

public class Test {

    static class NodeWrapper {
        public ListNode head;
        public ListNode nodeToDelete;

        NodeWrapper(ListNode head, ListNode nodeToDelete) {
            this.head = head;
            this.nodeToDelete = nodeToDelete;
        }
    }

    private static NodeWrapper buildListAndFindNode(int[] values, int valueToDelete) {
        ListNode head = new ListNode(values[0]);
        ListNode current = head;
        ListNode target = null;

        for (int i = 1; i < values.length; i++) {
            current.next = new ListNode(values[i]);
            current = current.next;
            if (values[i] == valueToDelete && target == null) {
                target = current;
            }
        }

        // Special case for head being the node to delete
        if (head.val == valueToDelete && target == null) {
            target = head;
        }

        return new NodeWrapper(head, target);
    }

    private static String listToString(ListNode head) {
        StringBuilder sb = new StringBuilder();
        while (head != null) {
            sb.append(head.val).append(" -> ");
            head = head.next;
        }
        return sb.append("null").toString();
    }

    private static int passed = 0;
    private static int total = 0;

    public static void runTest(int[] input, int deleteVal, int[] expected) {
        total++;
        NodeWrapper wrapper = buildListAndFindNode(input, deleteVal);

        if (wrapper.nodeToDelete == null || wrapper.nodeToDelete.next == null) {
            System.out.println("⚠️  Can't delete node with value: " + deleteVal + " (it's null or the last node)");
            return;
        }

        new Solution().deleteNode(wrapper.nodeToDelete);

        // Build expected string
        ListNode temp = wrapper.head;
        boolean match = true;
        for (int val : expected) {
            if (temp == null || temp.val != val) {
                match = false;
                break;
            }
            temp = temp.next;
        }

        match = match && temp == null;

        if (match) {
            System.out.println("✅ Test Passed");
            passed++;
        } else {
            System.out.println("❌ Test Failed. Final List: " + listToString(wrapper.head));
        }
    }

    public static void main(String[] args) {
        runTest(new int[]{4, 5, 1, 9}, 5, new int[]{4, 1, 9});
        runTest(new int[]{4, 5, 1, 9}, 1, new int[]{4, 5, 9});
        runTest(new int[]{1, 2}, 1, new int[]{2});
        runTest(new int[]{1, 2, 3, 4}, 3, new int[]{1, 2, 4});
        runTest(new int[]{10, 20, 30, 40, 50}, 30, new int[]{10, 20, 40, 50});
        runTest(new int[]{1, 100, 1000}, 100, new int[]{1, 1000});
        runTest(new int[]{0, -1, -2, -3}, -2, new int[]{0, -1, -3});
        runTest(new int[]{1000, 2000, 3000, 4000}, 3000, new int[]{1000, 2000, 4000});
        runTest(new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 6, new int[]{1, 2, 3, 4, 5, 7, 8, 9, 10});
        runTest(new int[]{1, 1, 1, 1}, 1, new int[]{1, 1, 1}); // Deletes only first matched 1 (non-tail)

        System.out.printf("\n✅ Passed %d / %d test cases!\n", passed, total);
    }
}
