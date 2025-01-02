class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        
        // Initialize pointers and variables for tracking water storage
        int left = 0, right = n - 1;
        int maxLeft = 0, maxRight = 0, ans = 0;

        // Two-pointer approach to calculate trapped water
        while (left <= right) {
            if (arr[left] < arr[right]) { 
                // If current height at left is less than or equal to maxLeft
                if (arr[left] >= maxLeft)
                    maxLeft = arr[left]; // Update maxLeft
                else
                    ans += maxLeft - arr[left]; // Calculate trapped water at left
                left++;
            } else {
                // If current height at right is less than or equal to maxRight
                if (arr[right] >= maxRight)
                    maxRight = arr[right]; // Update maxRight
                else
                    ans += maxRight - arr[right]; // Calculate trapped water at right
                right--;
            }
        }

        // Return the total amount of trapped water
        return ans;
    }
};

/*
Time Complexity:
- The algorithm iterates through the array once using the two-pointer approach.
- The time complexity is O(N), where N is the size of the array.

Space Complexity:
- The algorithm uses only a constant amount of extra space for variables.
- The space complexity is O(1).
*/
