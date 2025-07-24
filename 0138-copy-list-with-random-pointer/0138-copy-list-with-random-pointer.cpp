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

        // Step 1: Create mapping from original to copied nodes
        unordered_map<Node*, Node*> mp;

        Node* curr = head;
        while (curr) {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Step 2: Set next and random pointers for copied nodes
        curr = head;
        while (curr) {
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];
            curr = curr->next;
        }

        return mp[head];
    }
};
