class NumArray {
public:
    vector<int> pS; // Prefix sum array to store cumulative sums

    // Constructor to preprocess the prefix sum array
    NumArray(vector<int>& nums) {
        int n = nums.size(); // Size of the input array
        int sum = 0; // Variable to maintain the cumulative sum
        for (int i = 0; i < n; i++) {
            sum += nums[i]; // Update cumulative sum
            pS.push_back(sum); // Store the cumulative sum in the prefix sum array
        }
    }

    // Function to calculate the sum of elements in the range [left, right]
    int sumRange(int left, int right) {
        // Return the difference between the prefix sums to get the sum of the range
        return pS[right] - (left == 0 ? 0 : pS[left - 1]);
    }
};

/*
### Explanation:
1. **Purpose**:
   - This class efficiently calculates the sum of elements in a given range `[left, right]` in the array `nums`.
   - To achieve this, we preprocess the array to compute a **prefix sum array** (`pS`) where each element at index `i` represents the sum of the array elements from index `0` to `i`.

2. **Constructor**:
   - The constructor computes the prefix sum array in O(n) time by iterating over the input array and maintaining a running cumulative sum.

3. **sumRange()**:
   - To find the sum of elements in the range `[left, right]`, we use:
     - `pS[right]` to get the sum of elements from index `0` to `right`.
     - `pS[left - 1]` to subtract the sum of elements from index `0` to `left - 1`.
   - Special case: If `left == 0`, the sum of elements from index `0` to `left - 1` is `0`.

### Time Complexity:
1. **Constructor**: O(n)
   - Preprocessing the prefix sum array involves a single traversal of the input array.
2. **sumRange()**: O(1)
   - The sum for any range is computed in constant time using the prefix sum array.

### Space Complexity:
1. **O(n)**:
   - The prefix sum array requires additional space equal to the size of the input array.

### Example:
Input: `nums = [1, 2, 3, 4]`  
- Prefix sum array: `pS = [1, 3, 6, 10]`

1. Query: `sumRange(1, 3)`
   - Result: `pS[3] - pS[0] = 10 - 1 = 9`

2. Query: `sumRange(0, 2)`
   - Result: `pS[2] - 0 = 6`

3. Query: `sumRange(2, 2)`
   - Result: `pS[2] - pS[1] = 6 - 3 = 3`
*/
