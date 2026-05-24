class Solution {
public:
    int helper(int idx, int d, vector<int>&dp, vector<int>&arr){
        int n = arr.size();
    
        if(dp[idx] != -1){
            return dp[idx];
        }
        if(idx >= n || idx < 0)
            return 0;
        int ans = 1; 
        for(int i = 1; i <= d; i++){
            if(idx + i >= n || arr[idx + i] >= arr[idx])
                break;
            
            ans = max(ans, 1 + helper(idx + i, d, dp, arr));
        }
        for(int i = 1; i <= d; i++){
            if(idx - i < 0 || arr[idx - i] >= arr[idx])
                break;
            
            ans = max(ans, 1 + helper(idx - i, d, dp, arr));
        }
        
        return dp[idx] = ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);
        int ans = 1;
        for(int i = 0; i < n; i++){
            ans = max(ans, helper(i, d, dp, arr));
        }

        return ans;
    }
};
/*
6 4 14 6 8 13 9  7 10 6 12
*/