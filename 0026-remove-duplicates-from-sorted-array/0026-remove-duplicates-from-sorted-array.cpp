class Solution {
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0; // Pointer to track the position of the last unique element
        int n = nums.size();

        // Iterate through the array starting from the second element
        for (int j = 1; j < n; j++)
        {
            // If the current element is not equal to the previous unique element
            if (nums[i] != nums[j])
            {
                i++; // Move the pointer for unique elements
                nums[i] = nums[j]; // Place the current unique element in the correct position
            }
        }

        return i + 1; // The length of the array with unique elements
    }
};

/*
### Explanation:
1. **Purpose**: This function removes duplicates from a sorted array `nums` in-place and returns the length of the modified array containing only unique elements.
2. **Steps**:
   - Use two pointers:
     - `i` keeps track of the position of the last unique element in the array.
     - `j` iterates through the array to find new unique elements.
   - Compare `nums[i]` with `nums[j]`:
     - If they are different, it means `nums[j]` is a new unique element.
     - Increment `i` and copy the unique element `nums[j]` to `nums[i]`.
   - After the loop, `i + 1` gives the number of unique elements in the array.
3. **Key Assumption**: The input array `nums` is sorted, so all duplicates appear consecutively.

### Time Complexity:
- **O(n)**: The loop iterates through the array once, where `n` is the size of the array.

### Space Complexity:
- **O(1)**: The solution modifies the array in-place and does not use extra space.

### Notes:
- After calling this function, the first `i + 1` elements in the array `nums` will contain the unique elements.
- The elements after `i + 1` can remain unchanged, but they are not considered part of the modified array.

### Example:
Input: `nums = [1, 1, 2]`  
Output: `2`  
Modified Array: `[1, 2]`  

Input: `nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]`  
Output: `5`  
Modified Array: `[0, 1, 2, 3, 4]`  
*/
