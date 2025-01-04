class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;  // Deque to store indices of useful elements in the current window

        // Process the first window of size `k`
        for (int i = 0; i < k; i++) {
            // Remove indices of elements smaller than the current element from the back of the deque
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            // Add the current index to the deque
            dq.push_back(i);
        }

        vector<int> ans;  // Result to store the maximum of each window

        // Process the rest of the windows
        for (int i = 0; i < n - k; i++) {
            // Add the maximum of the current window (front of the deque) to the result
            ans.push_back(nums[dq.front()]);

            // Remove indices of elements smaller than the new element from the back of the deque
            while (!dq.empty() && nums[dq.back()] < nums[i + k]) {
                dq.pop_back();
            }

            // Remove the indices of elements that are out of the current window from the front of the deque
            while (!dq.empty() && dq.front() <= i) {
                dq.pop_front();
            }

            // Add the index of the new element to the deque
            dq.push_back(i + k);
        }

        // Add the maximum of the last window to the result
        ans.push_back(nums[dq.front()]);

        return ans;
    }
};

/*
Time Complexity:
- O(n), where n is the size of the input array `nums`.
  - Each element is added to and removed from the deque exactly once, resulting in linear time complexity.

Space Complexity:
- O(k), where k is the size of the sliding window.
  - The deque stores at most `k` indices at any given time.

Explanation of Complexity:
- The deque operations (push_back, pop_back, pop_front) are all O(1), and since each index is processed at most twice (once added and once removed), the total time complexity is O(n).
*/
