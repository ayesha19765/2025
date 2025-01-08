class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0; // Pointer starting from the leftmost element
        int right = height.size() - 1; // Pointer starting from the rightmost element
        int maxArea = 0; // Variable to store the maximum area found

        // Continue until the two pointers meet
        while (left < right) {
            // Calculate the area between the two pointers
            int currentArea = min(height[left], height[right]) * (right - left);
            // Update maxArea if the current area is greater
            maxArea = max(maxArea, currentArea);

            // Move the pointer pointing to the shorter line inward to potentially increase the area
            if (height[left] < height[right]) {
                left++; // Move the left pointer to the right
            } else {
                right--; // Move the right pointer to the left
            }
        }

        return maxArea; // Return the maximum area found
    }
};

/*
### Explanation:
1. **Purpose**: The function finds the maximum area of water that can be trapped between two lines in the input vector `height`.
   - Each element in `height` represents the height of a vertical line at that position.
   - The area between two lines is determined by the smaller height of the two lines multiplied by the distance between them.

2. **Two-Pointer Technique**:
   - Start with two pointers at the extremes of the array (`left` and `right`).
   - Calculate the area between the lines at the two pointers.
   - To maximize the area, move the pointer pointing to the shorter line inward, as moving the shorter line outward will not help increase the area.

3. **Key Insight**:
   - The width decreases as the two pointers approach each other, so to maximize the area, we must try to maximize the height of the shorter line.

### Time Complexity:
- **O(n)**: Each pointer moves inward at most `n` times, where `n` is the size of the input array.

### Space Complexity:
- **O(1)**: No additional space is used; the algorithm works in place.

### Example:
Input: `height = [1, 8, 6, 2, 5, 4, 8, 3, 7]`  
Output: `49`  
Explanation: The two lines at indices 1 and 8 form the container with the maximum area (height = 7, width = 7, area = 49).

Input: `height = [1, 1]`  
Output: `1`  
Explanation: The two lines at indices 0 and 1 form the container with the maximum area (height = 1, width = 1, area = 1).
*/
