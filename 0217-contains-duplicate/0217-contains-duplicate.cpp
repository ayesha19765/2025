class Solution {
public:
    // Function to determine if any value appears at least twice in the array
    bool containsDuplicate(vector<int>& nums) {
        // Initializing an unordered set with the elements from the nums vector.
        unordered_set<int> numSet(nums.begin(), nums.end());

        // If the size of the set is smaller than the size of the original vector,
        // it means there were duplicates which were removed in the set creation process.
        // Hence, return true if duplicates were found, false otherwise.
        return numSet.size() < nums.size();
    }
};
// Time - O(n)
// Space - O(n)