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
    void deleteNode(ListNode *node)
    {
        // The trick here is to copy the next node's val to current node and
        // delete next node
        node->val = node->next->val;
        node->next=node->next->next;
        return;
    }
};