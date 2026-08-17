class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int ans = 0;

        for (int num : set) {
            if (set.find(num - 1) == set.end()) { // Only start from the beginning of a sequence
                int curr = num;
                int length = 1;

                while (set.find(curr + 1) != set.end()) {
                    curr++;
                    length++;
                }

                ans = max(ans, length);
            }
        }

        return ans;
    }
};
