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
    ListNode* getKthNode(ListNode*temp, int k){
        k --;
        while(k && temp){
            temp = temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverseSeg(ListNode* curr){
        ListNode*prev = NULL;
        while(curr){
            ListNode*temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while(temp){
            ListNode* kthNode = getKthNode(temp, k);

            if(!kthNode){
                if(prevLast)    prevLast->next = temp;
                break;
            }
            // divide a segment
            ListNode* next = kthNode->next;
            kthNode->next = NULL;

            reverseSeg(temp);

            if(head == temp){
                head = kthNode;
            }else{
                prevLast->next = kthNode;
            }

            prevLast = temp;
            temp = next;
        }
        return head;
    }
};