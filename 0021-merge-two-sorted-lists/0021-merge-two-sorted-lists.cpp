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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to simplify edge cases
        ListNode dummy;
        ListNode* tail = &dummy; // Tail pointer to construct the merged list

        // Merge the two lists
        while (list1 && list2) {
            // Compare the current nodes of both lists and attach the smaller one
            if (list1->val < list2->val) {
                tail->next = list1;  // Attach list1's node
                list1 = list1->next; // Move to the next node in list1
            } else {
                tail->next = list2;  // Attach list2's node
                list2 = list2->next; // Move to the next node in list2
            }
            tail = tail->next; // Move the tail pointer
        }

        // Attach the remaining nodes from list1 or list2 (if any)
        tail->next = list1 ? list1 : list2;

        // Return the merged list starting from the next of dummy node
        return dummy.next;
    }
};

/*
Time Complexity:
- O(n + m), where n and m are the lengths of list1 and list2 respectively.
  - Each node of both lists is visited exactly once during the merging process.

Space Complexity:
- O(1), as the merging is done in place without using any additional memory for data structures.

Explanation of Complexity:
1. **Time Complexity:**
   - The while loop iterates through all nodes in both `list1` and `list2`.
   - After merging, attaching the remaining nodes (if any) takes O(1) time.

2. **Space Complexity:**
   - No extra space is used apart from a few pointers (`dummy`, `tail`, etc.), making it a constant space solution.

Advantages of Using a Dummy Node:
- Simplifies the implementation by handling edge cases (e.g., empty lists) without special conditions.
- Ensures the merged list always starts at `dummy.next`.
*/