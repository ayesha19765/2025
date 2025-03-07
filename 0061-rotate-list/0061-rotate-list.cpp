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
    int findLen(ListNode* head){
        int cnt = 1;
        ListNode*curr = head;
        while(curr->next){
            cnt++;
            curr = curr->next;
        }
        curr->next = head;
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return head;
        int len = findLen(head);
        k = k % len;
        ListNode* curr = head;
        for(int i = 0; i < len - k - 1; i++){
            curr = curr->next;
        }

        ListNode *newHead = curr->next;
        curr->next = NULL;
        return newHead;
    }
};