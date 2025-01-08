class Solution
{
public:
    vector<int> twoSum(vector<int> &arr, int k)
    {
        int i = 0, j = arr.size() - 1;

        // Use two-pointer approach to find two numbers that add up to 'k'
        while (i < j)
        {
            // If the sum of the elements at indices 'i' and 'j' equals 'k', return the indices
            if (arr[i] + arr[j] == k) 
                return {i + 1, j + 1}; // Indices are 1-based as per problem requirements

            // If the sum is greater than 'k', decrement 'j' to reduce the sum
            if (arr[i] + arr[j] > k) 
                j--;
            // If the sum is less than 'k', increment 'i' to increase the sum
            else 
                i++;
        }

        // Return {-1, -1} if no pair is found
        return {-1, -1};
    }
};

/*
### Explanation:
1. **Purpose**: This function finds two numbers in a sorted array that add up to a given target `k` and returns their indices (1-based).
2. **Steps**:
   - Use two pointers:
     - Start one pointer `i` at the beginning of the array.
     - Start the other pointer `j` at the end of the array.
   - Check the sum of the numbers at the two pointers:
     - If the sum equals `k`, return the indices (converted to 1-based).
     - If the sum is greater than `k`, decrement `j` to reduce the sum.
     - If the sum is less than `k`, increment `i` to increase the sum.
   - If the loop completes without finding a pair, return `{-1, -1}` to indicate no solution.

### Time Complexity:
- **O(n)**: Each element in the array is visited at most once due to the two-pointer approach.

### Space Complexity:
- **O(1)**: The solution uses a constant amount of extra space.

### Key Notes:
- The input array is assumed to be sorted, as this is a prerequisite for the two-pointer technique to work.
- If the array is not sorted, the solution would require additional preprocessing (sorting the array) with a time complexity of **O(n log n)**.
*/
