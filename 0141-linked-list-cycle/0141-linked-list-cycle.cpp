/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Use two pointers: slow and fast
        ListNode* slow = head;
        ListNode* fast = head;

        // Traverse the list
        while (fast && fast->next) { // Ensure fast and fast->next are not null
            slow = slow->next;          // Move slow pointer one step
            fast = fast->next->next;    // Move fast pointer two steps

            // Check if slow and fast meet (cycle detected)
            if (slow == fast) return true;
        }

        // If fast reaches null, there is no cycle
        return false;
    }
};

/*
Time Complexity:
- O(n), where n is the number of nodes in the linked list.
  - In the worst case, both slow and fast pointers traverse the list once.
  - The fast pointer moves at twice the speed of the slow pointer, so their traversal is linear overall.

Space Complexity:
- O(1), as only two pointers (`slow` and `fast`) are used.

Explanation of Complexity:
1. **Time Complexity:**
   - The `while` loop runs a maximum of `n` iterations in a list with `n` nodes.
   - If there is a cycle, the pointers will meet within one cycle length.

2. **Space Complexity:**
   - No extra space is used beyond the two pointers, making it a constant space solution.

Floyd's Cycle Detection Algorithm (Tortoise and Hare):
- The algorithm relies on two pointers:
  - `slow` pointer moves one step at a time.
  - `fast` pointer moves two steps at a time.
- If a cycle exists, the `slow` and `fast` pointers will eventually meet.
- If no cycle exists, the `fast` pointer will reach the end of the list (`nullptr`).

Advantages:
- Efficient in both time and space.
- Simple to implement with minimal overhead.

*/