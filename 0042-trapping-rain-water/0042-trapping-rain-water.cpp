class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size(); // Total number of elements in the array
        int left = 0, right = n - 1; // Two pointers, starting from the leftmost and rightmost ends
        int maxLeft = 0, maxRight = 0; // To track the maximum heights encountered so far from the left and right
        int ans = 0; // To store the total water trapped

        // Traverse the array until the two pointers meet
        while (left <= right) {
            if (arr[left] < arr[right]) {
                // If the current height on the left is less than the right, focus on the left side
                if (arr[left] >= maxLeft)
                    maxLeft = arr[left]; // Update the maximum height seen so far from the left
                else
                    ans += maxLeft - arr[left]; // Water trapped above the current block
                left++; // Move the left pointer to the right
            } else {
                // If the current height on the right is less than or equal to the left, focus on the right side
                if (arr[right] >= maxRight)
                    maxRight = arr[right]; // Update the maximum height seen so far from the right
                else
                    ans += maxRight - arr[right]; // Water trapped above the current block
                right--; // Move the right pointer to the left
            }
        }

        return ans; // Return the total water trapped
    }
};

/*
### Explanation:
1. **Purpose**:
   - Calculate the amount of water that can be trapped between bars of varying heights.
   - Water above a block is determined by the smaller of the maximum heights to its left and right, minus its height.

2. **Two-Pointer Approach**:
   - Use two pointers (`left` and `right`) to traverse the array from both ends.
   - Keep track of the maximum height seen so far from the left (`maxLeft`) and right (`maxRight`).
   - At each step:
     - If `arr[left] < arr[right]`, focus on the left pointer:
       - If `arr[left]` is greater than or equal to `maxLeft`, update `maxLeft`.
       - Otherwise, calculate the trapped water above `arr[left]` as `maxLeft - arr[left]`.
       - Move the left pointer to the right.
     - If `arr[right] <= arr[left]`, focus on the right pointer:
       - If `arr[right]` is greater than or equal to `maxRight`, update `maxRight`.
       - Otherwise, calculate the trapped water above `arr[right]` as `maxRight - arr[right]`.
       - Move the right pointer to the left.

3. **Key Insight**:
   - By focusing on the smaller height between `arr[left]` and `arr[right]`, we ensure that the trapped water is bounded by the shorter wall.

### Time Complexity:
- **O(n)**: The array is traversed once using two pointers.

### Space Complexity:
- **O(1)**: No extra space is used, as the algorithm operates in place.

### Example:
Input: `arr = [0,1,0,2,1,0,1,3,2,1,2,1]`  
Output: `6`  
Explanation:
- Water trapped between bars at indices 2 and 3 is 1 unit.
- Water trapped between bars at indices 4 and 7 is 4 units.
- Water trapped between bars at indices 8 and 10 is 1 unit.

Input: `arr = [4,2,0,3,2,5]`  
Output: `9`  
Explanation:
- Water trapped between bars at indices 1 and 5 is 9 units.

*/
