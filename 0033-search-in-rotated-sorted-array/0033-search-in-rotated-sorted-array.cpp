class Solution {
public:
    int search(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;

        // Binary search loop
        while (low <= high) {
            // Calculate the middle index to avoid overflow
            int mid = low + (high - low) / 2;

            // Check if the middle element is the target
            if (arr[mid] == target) 
                return mid;

            // Check if the left half [low, mid] is sorted
            if (arr[low] <= arr[mid]) {
                // If target lies within the sorted left half
                if (target >= arr[low] && target < arr[mid])
                    high = mid - 1; // Move to the left half
                else
                    low = mid + 1; // Move to the right half
            }
            // Otherwise, the right half [mid, high] is sorted
            else {
                // If target lies within the sorted right half
                if (target > arr[mid] && target <= arr[high])
                    low = mid + 1; // Move to the right half
                else
                    high = mid - 1; // Move to the left half
            }
        }

        // If the target is not found, return -1
        return -1;
    }
};

/*
Explanation:
- The array is sorted and rotated, so binary search is used with modifications.
- Determine which half of the array is sorted by comparing `arr[low]` and `arr[mid]`.
- Narrow down the search range based on whether the target lies within the sorted half.

Steps:
1. If `arr[mid]` equals the target, return `mid`.
2. If the left half `[low, mid]` is sorted:
   - Check if the target lies within this range and update `high` or `low` accordingly.
3. Otherwise, the right half `[mid, high]` is sorted:
   - Check if the target lies within this range and update `low` or `high` accordingly.
4. Repeat until the range is exhausted.

Time Complexity:
- O(log n): Binary search on the array.

Space Complexity:
- O(1): No additional space used.
*/
