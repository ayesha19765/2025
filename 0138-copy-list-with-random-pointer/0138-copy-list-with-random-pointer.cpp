/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        // 1. Create cloned nodes interleaved with original nodes
        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        // 2. Set random pointers for the copied nodes
        curr = head;
        while (curr) {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // 3. Separate the original and copied lists
        curr = head;
        Node* newHead = head->next;
        Node* copy = newHead;
        while (curr) {
            curr->next = curr->next->next;
            if (copy->next)
                copy->next = copy->next->next;
            curr = curr->next;
            copy = copy->next;
        }

        return newHead;
    }
};
