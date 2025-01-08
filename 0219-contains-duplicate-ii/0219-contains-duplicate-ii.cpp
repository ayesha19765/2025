class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();               // Get the size of the input array
        unordered_map<int, int> map;       // Create an unordered_map to store the last index of each element

        // Iterate through the array
        for(int i = 0; i < n; i++) {
            // If the current element has been seen before
            if(map.find(nums[i]) != map.end()) {
                int idx = map[nums[i]];   // Get the last index of the current element
                // If the difference between the current index and the previous index is <= k
                if(i - idx <= k) return true;  // We found a duplicate within the range of k
            }
            map[nums[i]] = i;   // Update the last seen index of the current element
        }
        return false;  // No duplicates found within the range k
    }
};

/*
### Explanation:
- We iterate through the array while keeping track of the last seen index of each element using an unordered_map.
- For each element, if it has been encountered before, we check whether the difference between the current index and the stored index is less than or equal to `k`. If so, we return true, indicating that a duplicate is found within the range.
- If no such duplicates are found after checking all elements, we return false.

### Time Complexity:
- The algorithm iterates through the array once, and each operation (finding and updating in the unordered_map) takes constant time on average.
- Thus, the time complexity is **O(n)**, where `n` is the number of elements in the array.

### Space Complexity:
- The space complexity is **O(n)**, where `n` is the number of distinct elements in the array, as we store the indices of each element in the unordered_map.
*/
