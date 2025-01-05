/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        // Base case: If the linked list is empty or has only one node, no reordering is needed
        if (!head) return;

        // Step 1: Find the middle of the linked list using the two-pointer approach
        ListNode *tmp = head, *half = head, *prev = NULL;
        while (tmp->next && tmp->next->next) {
            tmp = tmp->next->next; // Fast pointer moves two steps
            half = half->next;     // Slow pointer moves one step
        }

        // Step 2: Adjust for even-length lists (if the fast pointer reaches the last node)
        if (tmp->next) half = half->next;

        // Step 3: Reverse the second half of the linked list
        while (half) {
            tmp = half->next;  // Save the next node
            half->next = prev; // Reverse the current node's link
            prev = half;       // Move the `prev` pointer forward
            half = tmp;        // Move to the next node
        }
        half = prev; // `prev` now points to the head of the reversed second half

        // Step 4: Merge the two halves alternately
        while (head && half) {
            tmp = head->next;  // Save the next node of the first half
            prev = half->next; // Save the next node of the second half
            head->next = half; // Link the first node to the first node of the second half
            half->next = tmp;  // Link the second node of the second half to the next node of the first half
            head = tmp;        // Move the `head` pointer forward
            half = prev;       // Move the `half` pointer forward
        }

        // Step 5: Handle the edge case for even-length lists (close dangling pointers)
        if (head && head->next) head->next->next = NULL;
    }
};

/*
Time Complexity:
- O(n), where n is the number of nodes in the linked list.
  - Finding the middle of the list takes O(n).
  - Reversing the second half takes O(n/2) = O(n).
  - Merging the two halves takes O(n).
  - Overall, the operations are linear.

Space Complexity:
- O(1), as no extra space is used apart from a few pointers for traversal and manipulation.

Explanation:
1. **Finding the middle**:
   - Using the two-pointer approach, the `slow` pointer (`half`) reaches the middle when the `fast` pointer (`tmp`) reaches the end.
2. **Reversing the second half**:
   - The second half of the list is reversed in place using a standard linked list reversal technique.
3. **Merging the halves**:
   - Nodes from the first and reversed second half are alternately linked to achieve the reordered list.
4. **Edge cases**:
   - Handles even-length lists by ensuring no dangling pointers.

Advantages:
- Efficient in both time and space due to in-place operations.
- Clean implementation using standard linked list techniques.

*/