// Implementation of Kadane's Algorithm
class Solution {
public:
    // Function to find the maximum sum of a contiguous subarray
    int maxSubArray(vector<int> &nums) {
        int currSum = 0;              // Stores the current sum of the subarray
        int ans = INT_MIN;            // Initialize the answer with the smallest integer value

        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];       // Add the current element to the current sum
            ans = max(ans, currSum);  // Update the maximum subarray sum
            if (currSum < 0)          // If the current sum becomes negative, reset it to 0
                currSum = 0;
        }

        return ans; // Return the maximum subarray sum
    }
};

/*
Time Complexity:
- The algorithm traverses the array once, performing constant-time operations for each element.
- Therefore, the time complexity is O(n), where n is the size of the array.

Space Complexity:
- The algorithm uses a constant amount of extra space (variables `currSum` and `ans`).
- Therefore, the space complexity is O(1).

Key Points:
1. Kadane's Algorithm efficiently finds the maximum sum of a contiguous subarray.
2. If all elements are negative, it will return the largest (least negative) element, as resetting `currSum` to 0 ensures no smaller sum affects the result.
3. This algorithm is optimal for solving the "maximum subarray sum" problem.
*/
