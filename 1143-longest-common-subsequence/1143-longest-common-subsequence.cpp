class Solution {
public:
// // dp + memo
    // int solve(int i, int j, string text1, string text2, vector<vector<int>>&dp){
    //     if(i == text1.size() || j == text2.size()){
    //         return 0;
    //     }

    //     if(dp[i][j] != -1)
    //         return dp[i][j];
    //     int ans = 0;
    //     if(text1[i] == text2[j])
    //     {
    //         ans = max(ans, 1 + solve(i + 1, j + 1, text1, text2, dp));
    //     }

    //     ans = max(ans, max(solve(i + 1, j, text1, text2, dp), solve(i, j + 1, text1, text2, dp)));

    //     return dp[i][j] = ans;
    // }
    // int longestCommonSubsequence(string text1, string text2) {
    //     vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
    //     return solve(0, 0, text1, text2, dp);
    // }

// space optimised
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), 0));

        int n = text1.size(), m = text2.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int ans = 0;
                if(text1[i] == text2[j]){
                    ans = max(ans, 1 + ((i > 0 && j > 0)? dp[i - 1][j - 1]: 0));
                }
                if(i > 0)
                    ans = max(ans, dp[i - 1][j]);

                if(j > 0)
                    ans = max(ans, dp[i][j - 1]);

                dp[i][j] = ans;
            }
        }

        return dp[n - 1][m - 1];
    }   
};