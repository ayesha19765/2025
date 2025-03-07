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
    ListNode* findMid(ListNode* head){
        ListNode* slow = head, *fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL, *temp = head;

        while(temp){
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }

    bool compare(ListNode* head1, ListNode* head2){
        while(head1 && head2){
            if(head1->val != head2->val)
                return false;

            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
            return true;

        ListNode*mid = findMid(head);
        mid = reverse(mid);
        return compare(mid, head);
    }
};

// O(n) -> time
// O(1) -> space

// O(n) -> time
