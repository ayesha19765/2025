class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int start = 0, end = 0, minLen = INT_MAX, size = nums.size();
        int sum = 0;

        // Iterate through the array with a sliding window
        while (end < size) {
            // Expand the window by adding the current element to the sum
            if (sum < target) 
                sum += nums[end++];

            // Shrink the window while the sum is greater than or equal to the target
            while (sum >= target) {
                minLen = min(minLen, end - start);  // Update the minimum length of the subarray
                sum -= nums[start];  // Remove the leftmost element from the sum
                start++;  // Shrink the window from the left
            }
        }

        // If no valid subarray is found, return 0
        return (minLen == INT_MAX) ? 0 : minLen;
    }
};

/*
### Explanation:
- We use a sliding window approach with two pointers (`start` and `end`) to track the subarray.
- The `end` pointer is used to expand the window, while the `start` pointer shrinks it to find the minimum length of the subarray that sums up to at least the target.
- Each time the sum is greater than or equal to the target, we update the minimum length (`minLen`) and shrink the window by moving the `start` pointer.
- If no valid subarray is found, we return `0`.

### Time Complexity:
- We iterate through the array with the `end` pointer, and for each position of `end`, the `start` pointer only moves forward. Therefore, each pointer moves at most `n` times.
- Hence, the time complexity is **O(n)**, where `n` is the number of elements in the array.

### Space Complexity:
- The space complexity is **O(1)** as we are using a fixed amount of extra space for variables (`start`, `end`, `sum`, `minLen`).

*/
