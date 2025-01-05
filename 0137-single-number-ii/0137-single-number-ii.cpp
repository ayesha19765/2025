class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int mask[32] = {0};  // Array to store the count of 1s at each bit position

        // Count the number of 1s at each bit position for all numbers
        for (int i : nums) {
            for (int idx = 0; idx < 32; idx++) {
                // Check if the idx-th bit of the number is 1
                if (i & (1 << idx)) {
                    mask[idx]++;  // Increment the count of 1s for this bit position
                }
            }
        }

        int ans = 0;  // Variable to store the result, the single number

        // Reconstruct the single number from the mask array
        for (int i = 0; i < 32; i++) {
            // Only consider bits where the count of 1s is not divisible by 3
            if (mask[i] % 3) {  // If the bit appears a number of times that isn't a multiple of 3
                ans |= (1 << i);  // Set the ith bit in ans
            }
        }

        // Handle two's complement for negative numbers
        if (mask[31] % 3 != 0) {  // If the MSB (31st bit) is set, the number is negative
            ans -= (1LL << 32);  // Convert to two's complement negative representation
        }

        return ans;  // Return the reconstructed single number
    }
};

/*
### Time Complexity:
- **O(n)**:
  - The outer loop runs `n` times where `n` is the number of elements in the `nums` array.
  - The inner loop runs 32 times, as we are processing each bit position of the integers (32-bit integers).
  - Thus, the total time complexity is O(n * 32) = O(n), where `n` is the number of elements in the array.

### Space Complexity:
- **O(1)**:
  - The space used is constant because we are only using a fixed-size array `mask` of length 32 to store the count of 1s at each bit position.
  - Therefore, the space complexity is O(1), as the size of the `mask` array does not depend on the input size.

### Notes:
- The algorithm counts the number of times each bit position is set to 1 across all numbers in the array.
- The result is reconstructed by taking the remainder when the count of 1s is divided by 3, as all numbers except one appear 3 times.
- If the 31st bit (MSB) is set, the number is negative and we adjust for the two's complement representation.
*/
