class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        // Initialize two pointers: one at the beginning (i) and one at the end (j)
        int i = 0, j = arr.size() - 1;

        // Loop until the two pointers meet
        while(i < j) {
            // Check if the sum of the elements at the two pointers equals the target
            if(arr[i] + arr[j] == target) {
                return {i + 1, j + 1}; // Return 1-based indices if a match is found
            } else if(arr[i] + arr[j] > target) {
                j--; // Move the right pointer left if the sum is greater than the target
            } else {
                i++; // Move the left pointer right if the sum is less than the target
            }
        }

        // Return {-1, -1} if no valid pair is found
        return {-1, -1};
    }
};

/*
Time Complexity:
- The two-pointer approach scans the array once, making the time complexity O(N), where N is the size of the array.

Space Complexity:
- The algorithm uses constant space for the pointers, so the space complexity is O(1).
*/
