class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> s; // Monotonic stack to store indices of temperatures
        vector<int> ans(t.size()); // Result vector to store the number of days

        // Traverse the temperatures array from right to left
        for (int i = t.size() - 1; i >= 0; i--) {
            // Pop elements from the stack while the current temperature is greater
            while (!s.empty() && t[s.top()] <= t[i])
                s.pop();

            // Calculate the number of days to a warmer temperature
            ans[i] = s.empty() ? 0 : s.top() - i;

            // Push the current index onto the stack
            s.push(i);
        }

        return ans;
    }
};

/*
Time Complexity:
- O(n), where n is the number of elements in the `t` array. Each element is pushed and popped from the stack once.

Space Complexity:
- O(n), for the stack used to store indices.
*/
