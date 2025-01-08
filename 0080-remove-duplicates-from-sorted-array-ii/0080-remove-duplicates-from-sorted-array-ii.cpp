class Solution
{
    public:
        int removeDuplicates(vector<int> &nums)
        {
            int i = 0; // Pointer to track the position for the next allowed duplicate
            int n = nums.size(); // Total size of the array
            int j = 2; // Pointer to traverse the array from the 3rd element

            // Traverse the array starting from the 3rd element
            while (j < nums.size())
            {
                // If the current element is not the same as the element at `i`,
                // it means this element can be added without violating the "at most twice" rule
                if (nums[i] != nums[j])
                {
                    nums[i + 2] = nums[j]; // Place the current element at the correct position
                    i++; // Increment `i` to point to the next position for potential duplicate
                }
                j++; // Move to the next element
            }

            // The valid length of the modified array is either `i + 2` or the original size `n`, whichever is smaller
            return min(i + 2, n);
        }
};

/*
### Explanation:
1. **Purpose**: This function modifies the sorted array `nums` in place to allow each element to appear at most twice. It returns the new length of the array with the duplicates restricted to at most twice.
2. **Steps**:
   - Use two pointers:
     - `i` tracks the last position where duplicates are allowed up to 2 times.
     - `j` iterates through the array to find elements that can be added to the modified array.
   - Compare `nums[i]` with `nums[j]`:
     - If they are different, copy `nums[j]` to `nums[i + 2]`.
     - Increment `i` to move to the next position for adding a new element.
   - The loop ensures that duplicates are allowed up to twice while maintaining the order of the elements.
3. **Key Assumption**: The input array `nums` is sorted, so all duplicates are consecutive.

### Time Complexity:
- **O(n)**: The loop iterates through the array once, where `n` is the size of the array.

### Space Complexity:
- **O(1)**: The solution modifies the array in place and does not use extra space.

### Notes:
- The function ensures that the first `i + 2` elements in `nums` contain the modified array with at most two occurrences of each element.
- The elements after the returned length may remain unchanged but are not part of the modified array.

### Example:
Input: `nums = [1, 1, 1, 2, 2, 3]`  
Output: `5`  
Modified Array: `[1, 1, 2, 2, 3]`

Input: `nums = [0, 0, 1, 1, 1, 1, 2, 3, 3]`  
Output: `7`  
Modified Array: `[0, 0, 1, 1, 2, 3, 3]`
*/
