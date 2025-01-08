class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        long long sum = 0, ans = 0;  // Initialize variables for sum of subarray and result

        // Iterate through the array
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];  // Add the current element to the sum

            // Check if we have a subarray of size 'k'
            if(i + 1 >= k) {
                // If the average of the current subarray is greater than or equal to the threshold, increment the result
                ans += (((sum * 1.0) / k) >= threshold);
                sum -= arr[i - k + 1];  // Subtract the element that is leaving the window
            }
        }

        return ans;  // Return the total number of subarrays satisfying the condition
    }
};

/*
### Explanation:
- We maintain a sliding window of size `k` to keep track of the sum of the subarray.
- For each new element added to the window, we check if the average of the current subarray is greater than or equal to the `threshold`.
- If it satisfies the condition, we increment the count (`ans`).
- We remove the element that leaves the window to maintain the subarray size `k`.

### Time Complexity:
- The algorithm iterates through the array once, and each operation (adding and subtracting elements from the sum) takes constant time.
- Thus, the time complexity is **O(n)**, where `n` is the number of elements in the array.

### Space Complexity:
- The space complexity is **O(1)**, as we are using a fixed amount of extra space (for `sum` and `ans`) irrespective of the input size.
*/
