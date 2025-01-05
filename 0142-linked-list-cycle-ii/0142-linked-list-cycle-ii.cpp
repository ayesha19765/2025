/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    // Helper function to find the start of the cycle
    ListNode *startOfCycle(ListNode *slow, ListNode *fast) {
        // Move both pointers one step at a time until they meet
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast; // The start of the cycle
    }

    ListNode *detectCycle(ListNode *head) {
        // Initialize two pointers for the cycle detection
        ListNode *slow = head, *fast = head;

        // Use the Floyd's Tortoise and Hare algorithm to detect a cycle
        while (fast && fast->next) {
            fast = fast->next->next; // Move fast pointer two steps
            slow = slow->next;       // Move slow pointer one step

            // If the slow and fast pointers meet, there is a cycle
            if (slow == fast)
                return startOfCycle(slow, head); // Find and return the start of the cycle
        }

        // No cycle found
        return NULL;
    }
};

/*
Time Complexity:
- O(n), where n is the number of nodes in the linked list.
  - The first part (cycle detection) takes O(n), as both pointers traverse the list at most once.
  - The second part (finding the start of the cycle) also takes O(n), but combined it is still O(n).

Space Complexity:
- O(1), as the algorithm uses a constant amount of extra space.

Explanation:
1. **Cycle Detection**:
   - The Floyd's Tortoise and Hare algorithm uses two pointers (`slow` and `fast`).
   - If there’s a cycle, the fast pointer will eventually meet the slow pointer.

2. **Finding the Start of the Cycle**:
   - Once the slow and fast pointers meet, reset one pointer (`fast`) to the head.
   - Move both pointers one step at a time. They will meet at the start of the cycle.

3. **Edge Cases**:
   - If the list is empty (`head == NULL`) or contains no cycle, the function returns `NULL`.

4. **Efficient**:
   - The algorithm is highly efficient with O(n) time and O(1) space.
*/