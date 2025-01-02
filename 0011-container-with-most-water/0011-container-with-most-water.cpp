class Solution {
public:
    int maxArea(vector<int>& height) {
        // Initialize two pointers, one at the beginning and one at the end of the array
        int left = 0;
        int right = height.size() - 1;

        // Variable to store the maximum area found
        int maxArea = 0;

        // Loop until the two pointers meet
        while (left < right) {
            // Calculate the current area using the minimum height and the distance between the pointers
            int currentArea = min(height[left], height[right]) * (right - left);

            // Update the maximum area if the current area is larger
            maxArea = max(maxArea, currentArea);

            // Move the pointer pointing to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        // Return the maximum area found
        return maxArea;
    }
};

/*
Time Complexity:
- The algorithm uses a two-pointer approach that scans the array once.
- The time complexity is O(N), where N is the number of elements in the input array.

Space Complexity:
- The algorithm uses only a constant amount of extra space for variables.
- The space complexity is O(1).
*/
