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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a dummy node to act as the starting point of the result list
        ListNode head;
        ListNode *curr = &head; // Pointer to build the result list

        int carry = 0; // Initialize carry to 0

        // Traverse both linked lists and handle the carry
        while (l1 || l2 || carry) {
            // Add the value from l1 if it exists
            if (l1) {
                carry += l1->val;
                l1 = l1->next; // Move to the next node
            }

            // Add the value from l2 if it exists
            if (l2) {
                carry += l2->val;
                l2 = l2->next; // Move to the next node
            }

            // Create a new node with the digit (carry % 10)
            curr->next = new ListNode(carry % 10);

            // Update carry for the next iteration
            carry /= 10;

            // Move the current pointer to the newly created node
            curr = curr->next;
        }

        // Return the head of the result list (skipping the dummy node)
        return head.next;
    }
};

/*
Time Complexity:
- O(max(m, n)), where m is the length of `l1` and n is the length of `l2`.
  - Each node in both linked lists is processed exactly once.

Space Complexity:
- O(max(m, n)), as a new linked list is created to store the result.
  - Each node in the result list corresponds to a sum of digits or the carry.

Explanation:
1. **Dummy Node Technique**:
   - The dummy node simplifies the logic for adding nodes to the result list.
   - The final result starts from `head.next`, as `head` is a placeholder.

2. **Carry Handling**:
   - Carry is maintained across iterations to handle sums greater than 9.
   - After calculating `carry % 10` for the current digit, `carry` is updated as `carry / 10`.

3. **Edge Cases**:
   - Handles cases where one list is longer than the other.
   - If there’s a leftover carry after processing both lists, it’s added as a new node.

4. **Efficient**:
   - Uses constant space for pointers and only allocates space for the result nodes.
*/