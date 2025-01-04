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
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        // Base case: If the list is empty or has only one node, return the head
        if (head == nullptr || head->next == nullptr) 
            return head;

        // Recursively reverse the rest of the list
        ListNode *p = reverseList(head->next);

        // Adjust the pointers to reverse the current link
        head->next->next = head; // Point the next node's next to the current node
        head->next = nullptr;   // Break the original link

        // Return the new head of the reversed list
        return p;
    }
};

/*
Time Complexity:
- O(n), where n is the number of nodes in the linked list.
  - Each node is visited exactly once during the recursion.

Space Complexity:
- O(n), due to the recursive call stack.
  - There are n recursive calls in the worst case (one for each node in the linked list).

Explanation of Complexity:
1. **Time Complexity:**
   - The algorithm processes each node exactly once to reverse its pointer, leading to a linear runtime.

2. **Space Complexity:**
   - The recursion stack requires additional memory, proportional to the depth of the recursion, which is equal to the number of nodes in the linked list.
*/
