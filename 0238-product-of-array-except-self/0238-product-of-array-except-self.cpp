class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Initialize the result vector with size equal to nums and all elements as 1
        vector<int> res(nums.size(), 1);

        // Calculate the prefix product for each element
        for(int i = 1; i < nums.size(); i++)
            res[i] = res[i-1] * nums[i-1];

        // Calculate the suffix product while updating the result vector
        int right = 1; // Variable to keep track of the product of elements to the right
        for(int i = nums.size() - 1; i >= 0; i--) {
            res[i] *= right; // Multiply the prefix product with the suffix product
            right *= nums[i]; // Update the suffix product
        }

        return res; // Return the result vector
    }
};

/*
Time Complexity:
- Prefix calculation: O(N), where N is the size of the input array.
- Suffix calculation: O(N).
- Overall: O(N).

Space Complexity:
- Output array res takes O(N) space.
- No extra space apart from variables (in-place computation).
- Overall: O(N).
*/
