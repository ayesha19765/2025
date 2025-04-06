class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& dp, vector<int>& child) {
        if (i == nums.size())
            return 0;
        
        if (dp[i] != -1)
            return dp[i];
        
        int ans = 1;
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] % nums[i] == 0) {
                int next = 1 + solve(j, nums, dp, child);
                if (next > ans) {
                    ans = next;
                    child[i] = j;
                }
            }
        }
        return dp[i] = ans;
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        
        sort(nums.begin(), nums.end());
        vector<int> dp(n, -1);
        vector<int> child(n, -1);

        int maxLen = 0, startIndex = 0;
        for (int i = 0; i < n; i++) {
            int currentLen = solve(i, nums, dp, child);
            if (currentLen > maxLen) {
                maxLen = currentLen;
                startIndex = i;
            }
        }

        vector<int> res;
        for (int i = startIndex; i != -1; i = child[i]) {
            res.push_back(nums[i]);
        }

        return res;
    }
};
