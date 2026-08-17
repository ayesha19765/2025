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
    ListNode* reverseLL(ListNode* node){
        ListNode* prev = NULL, *curr = node;
        while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head)   return true;

        ListNode* fast = head, *slow = head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        // cout << slow->val << endl;

        fast = reverseLL(slow);
        slow = head;

        while(slow && fast){
            if(slow->val != fast->val){
                return false;
            }

            slow = slow->next;
            fast = fast->next;
        }

        return true;
    }
};