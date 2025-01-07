// credits:
// https://leetcode.com/problems/maximum-sum-circular-subarray/solutions/633401/kadane-algorithm-trick-beats-100-java-explained
// IMPPPPP
// For non circular sum,
// Step 1) find the minimum subarray sum of array.
// -2-3 =-5
// Step 2) Now find the total sum of array = 1 + 2 + 5 -2 - 3 + 5 = 8
// Step 3) The max subarray sum for circular array = Total Sum - Minimum subarray Sum
// = 8 - (-5) = 8 + 5 =13
// As illustrated above, substracting minimum subarray sum from total sum gives maximum circular subarray sum.Answer = Max (Non circular max sum + circular max sum)= max(8,13) = 13
// 
// The trick here is that to find the minimum subarray sum, we invert the sign of all the numbers in original subarray, and find the maximum subarray sum using Kadane algorithm. Then add it with the total sum. (which is similar to
//[total - minimum subarray sum ])

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &A)
    {
        // Step 1: Find the maximum subarray sum using Kadane's algorithm (Non-circular case)
        // Kadane's algorithm finds the maximum sum of a subarray without considering the circular nature.
        int nonCircularSum = kadaneMaxSum(A);

        // Step 2: Calculate the total sum of the array
        int totalSum = 0;
        for (int i = 0; i < A.size(); i++)
        {
            totalSum += A[i]; // Accumulate the total sum of the array
            A[i] = -A[i];     // Invert the sign of each element to find the minimum subarray sum later
        }

        // Step 3: Calculate the circular sum
        // The circular subarray sum is equivalent to the total sum of the array minus the minimum subarray sum.
        // This can be achieved by using Kadane's algorithm on the inverted array.
        int circularSum = totalSum + kadaneMaxSum(A); // Adding max sum of inverted array, which corresponds to the minimum subarray sum in original array

        // Edge Case: If the circular sum is 0, it means all elements are negative and the circular subarray is invalid.
        // In this case, the result should be the non-circular subarray sum.
        if (circularSum == 0)
            return nonCircularSum;

        // Step 4: Return the maximum of non-circular and circular subarray sums.
        return max(circularSum, nonCircularSum);
    }

    // Helper function to calculate the maximum subarray sum using Kadane's algorithm
    // Kadane's algorithm works by iterating through the array and maintaining a running sum.
    // If the running sum becomes negative, it is reset to 0, as any negative sum will only reduce the overall subarray sum.
    int kadaneMaxSum(vector<int> &A)
    {
        int currentSum = A[0]; // Initialize current sum to the first element
        int maxSum = A[0];     // Initialize max sum to the first element
        for (int i = 1; i < A.size(); i++)
        {
            if (currentSum < 0)
                currentSum = 0; // Reset current sum if it's negative, as it wouldn't contribute to a larger sum
            currentSum = A[i] + currentSum; // Update the current sum by adding the current element
            maxSum = max(maxSum, currentSum); // Update max sum if the current sum is larger
        }
        return maxSum; // Return the maximum subarray sum found
    }
};

/*
### Time Complexity:
1. **Kadane's algorithm (Non-circular sum)**: O(n), where n is the size of the array.
   - We traverse the array once to find the maximum subarray sum for the non-circular case.
   
2. **Total sum calculation and array inversion**: O(n), where n is the size of the array.
   - We traverse the array once to compute the total sum and invert the signs of the elements.

3. **Kadane's algorithm (Circular sum)**: O(n), where n is the size of the array.
   - We apply Kadane's algorithm again on the inverted array to find the maximum subarray sum, which corresponds to the minimum subarray sum in the original array.

4. **Overall Time Complexity**: O(n) due to the linear scans for Kadane's algorithm and array manipulation (total sum and inversion).

### Space Complexity:
1. **In-place modification**: The algorithm modifies the input array A in-place, so no extra space is used for storing intermediate arrays.
2. **Auxiliary space**: Only a few integer variables (currentSum, maxSum, totalSum, circularSum) are used, all of which require constant space.

3. **Overall Space Complexity**: O(1), since only a constant amount of extra space is used.

### Edge Cases:
1. **All elements are negative**:
   - In this case, Kadane's algorithm will return the least negative number, and the circular sum will be 0, so the answer will be the non-circular sum.
   
2. **Single-element array**:
   - The result will be the same for both non-circular and circular sums, as there's only one element.

3. **All positive elements**:
   - The circular sum will give the maximum sum because the entire array is valid as a circular subarray.

4. **Array with both positive and negative elements**:
   - The algorithm correctly handles both the non-circular and circular subarray cases and returns the maximum sum between the two.

### Key Idea:
- **Non-circular subarray** is found using Kadane’s algorithm.
- **Circular subarray** is found by inverting the array, applying Kadane’s algorithm again, and then using the formula:
  **Circular sum = Total sum - Minimum subarray sum**.
- This trick works because the minimum subarray sum is equivalent to the maximum sum in the inverted array.

### Example:
- For an array [1, 2, 5, -2, -3, 5], the non-circular max sum is 8 (subarray [1, 2, 5]), and the circular max sum is 13 (subarray [5, -2, -3, 5]). The final answer is the maximum of these two values, which is 13.
*/
