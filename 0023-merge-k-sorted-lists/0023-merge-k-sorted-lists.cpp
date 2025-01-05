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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        // Priority queue to store the values from all the lists, in ascending order.
        priority_queue<int, vector<int>, greater<int>> q;

        // Push all values from the linked lists into the priority queue
        for (int i = 0; i < lists.size(); i++)
        {
            // Traverse each linked list and push its values into the priority queue
            while (lists[i] != NULL)
            {
                q.push(lists[i]->val);  // Push current node's value
                lists[i] = lists[i]->next;  // Move to the next node
            }
        }

        // Create a dummy node to simplify list construction
        ListNode *dummy = new ListNode(0);
        ListNode *current = dummy;  // Pointer to build the new merged list

        // Iterate until the priority queue is empty
        while (!q.empty())
        {
            // Get the smallest value from the priority queue
            current->next = new ListNode(q.top());  // Create a new node with the smallest value
            q.pop();  // Remove the smallest value from the priority queue
            current = current->next;  // Move to the next node in the merged list
        }

        // The head of the merged linked list is the next of the dummy node
        return dummy->next;
    }
};

/*
### Time Complexity:
- **O(N log K)**: 
  - Pushing each element from all the lists into the priority queue takes O(log K) time (where K is the number of lists).
  - For N total elements across all the lists, the time complexity for inserting into the priority queue is O(N log K).
  - Finally, constructing the merged list from the priority queue also takes O(N) time, which is dominated by the priority queue operations.

### Space Complexity:
- **O(N)**:
  - We are using a priority queue to store all the elements from all the lists. Therefore, the space required is O(N), where N is the total number of nodes across all the lists.
  - Additionally, the merged list will also require space proportional to the number of nodes, which is O(N).

### Explanation:
- The priority queue ensures that we always get the smallest element among all the linked lists in each iteration.
- We traverse all the lists and add their values to the priority queue, then extract the smallest values from the queue and construct the new merged linked list.
- This approach ensures that the merged list is created in sorted order by maintaining the priority queue, with the smallest element always at the top.
*/
