class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Handle edge case where the input array is empty
        if(nums.size() == 0) return 0;

        // Sort the array to bring consecutive elements together
        sort(nums.begin(), nums.end());

        // Initialize variables for the maximum sequence length (ans)
        // and current sequence length (curr)
        int ans = 1, prev = nums[0], curr = 1;

        // Traverse the sorted array
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == prev + 1) {
                // If the current number is consecutive, increment the current sequence length
                curr++;
            } else if(nums[i] != prev) {
                // Reset the current sequence length if the current number breaks the sequence
                curr = 1;
            }
            prev = nums[i]; // Update the previous number
            ans = max(ans, curr); // Update the maximum sequence length
        }

        return ans; // Return the length of the longest consecutive sequence
    }
};

/*
Time Complexity:
- Sorting the array: O(N * log N), where N is the size of the input array.
- Single traversal of the sorted array: O(N).
- Overall: O(N * log N).

Space Complexity:
- Sorting requires O(N) space in the worst case (depending on the sorting algorithm used).
- No additional space is used apart from variables.
- Overall: O(N).
*/
