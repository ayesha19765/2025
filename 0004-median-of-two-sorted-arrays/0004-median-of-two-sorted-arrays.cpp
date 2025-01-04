class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        // Ensure nums1 is the smaller array for simplicity
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);

        int n = n1 + n2;
        int left = (n1 + n2 + 1) / 2; // Size of left partition
        int low = 0, high = n1;

        while (low <= high) {
            int mid1 = (low + high) / 2; // Partition index for nums1
            int mid2 = left - mid1;      // Partition index for nums2

            // Elements around the partition
            int l1 = (mid1 > 0) ? nums1[mid1 - 1] : INT_MIN;
            int r1 = (mid1 < n1) ? nums1[mid1] : INT_MAX;
            int l2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;
            int r2 = (mid2 < n2) ? nums2[mid2] : INT_MAX;

            if (l1 <= r2 && l2 <= r1) {
                // Correct partition found
                if (n % 2 == 1)
                    return max(l1, l2); // Median for odd total length
                else
                    return ((double)(max(l1, l2) + min(r1, r2))) / 2.0; // Median for even total length
            } else if (l1 > r2) {
                // Move left in nums1
                high = mid1 - 1;
            } else {
                // Move right in nums1
                low = mid1 + 1;
            }
        }

        return 0.0; // Inputs are not sorted or valid
    }
};

/*
### Explanation:
1. **Partitioning Logic**:
   - Divide the combined arrays into two halves, ensuring the left half has the smaller elements.
   - Maintain the property: `l1 <= r2` and `l2 <= r1`.

2. **Key Variables**:
   - `l1`, `r1`: Left and right elements around the partition in `nums1`.
   - `l2`, `r2`: Left and right elements around the partition in `nums2`.

3. **Binary Search**:
   - Adjust the partition in `nums1` (`low`, `high`) based on comparisons of `l1, r2` and `l2, r1`.

4. **Time Complexity**:
   - O(log(min(n1, n2))) for binary search on the smaller array.

5. **Space Complexity**:
   - O(1): No additional space used.
*/
