class Solution {
public:
    int findMin(vector<int>& arr) {
        int start = 0, end = arr.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            // If the subarray is sorted, the minimum is at the start
            if (arr[start] < arr[end]) {
                return arr[start];
            }

            // Determine which half to search
            if (arr[mid] > arr[end]) {
                start = mid + 1; // Minimum lies in the right half
            } else {
                end = mid; // Minimum lies in the left half, including mid
            }
        }

        // When start == end, the minimum element is found
        return arr[start];
    }
};

/*
Explanation:
- The rotated sorted array has two parts:
  1. The ascending part before the rotation point.
  2. The ascending part after the rotation point.
- The minimum element is the rotation point.

Steps:
1. Use binary search to find the minimum.
2. If the subarray is sorted (`arr[start] < arr[end]`), return `arr[start]`.
3. If `arr[mid] > arr[end]`, the minimum is in the right half.
4. If `arr[mid] <= arr[end]`, the minimum is in the left half.

Time Complexity:
- O(log n): Binary search reduces the range by half at each step.

Space Complexity:
- O(1): No additional data structures are used.
*/
