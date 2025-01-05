class Solution {
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int xorSum = 0;
        
        // XOR all numbers in the array. The result will be the XOR of the two single numbers
        // because all other numbers appear twice and will cancel out.
        for (int i = 0; i < nums.size(); i++)
            xorSum = xorSum ^ nums[i];

        // Find the first bit that is set in xorSum (i.e., the bit that is different between the two unique numbers)
        int pos = 0;
        while (xorSum) {
            if (xorSum & (1 << pos))  // If the pos-th bit is set in xorSum
                break;  // Found the first set bit
            pos++;  // Move to the next bit
        }

        // Create a mask where only the pos-th bit is set
        xorSum = (1 << pos);

        // Initialize a vector to store the two unique numbers
        vector<int> ans(2, 0);

        // Split the numbers into two groups based on the pos-th bit.
        // If the bit is set in a number, XOR it with ans[0]; otherwise, XOR it with ans[1].
        for (int i = 0; i < nums.size(); i++) {
            if (xorSum & nums[i])  // If the pos-th bit is set in nums[i]
                ans[0] ^= nums[i];  // XOR with ans[0]
            else
                ans[1] ^= nums[i];  // XOR with ans[1]
        }

        // Return the two single numbers
        return ans;
    }
};

/*
### Time Complexity:
- **O(n)**:
  - The first loop iterates through the `nums` array once, performing XOR on all elements, which is O(n).
  - The second loop also iterates through the `nums` array to divide numbers into two groups and perform XOR again, which is also O(n).
  - Therefore, the total time complexity is O(n), where `n` is the number of elements in the array.

### Space Complexity:
- **O(1)**:
  - The space used is constant because we are only using a fixed number of extra variables (like `xorSum`, `pos`, and `ans`).
  - Therefore, the space complexity is O(1), as the space does not depend on the input size.

### Explanation:
- XOR of all the numbers gives a result where only the two unique numbers remain, because the duplicate numbers cancel out.
- We then find the first bit where these two numbers differ and partition the numbers into two groups based on that bit.
- Finally, XORing the numbers in each group results in the two unique numbers.
*/
