class Solution {
public:
    int solve(int i,  vector<vector<int>> &arr, int m, int n, vector<vector<vector<int>>> &dp){
        if(m == 0 && n == 0)
            return 0;
        if(i == arr.size())
            return 0;
        if(dp[i][m][n] != -1)
            return dp[i][m][n];
        int ans = INT_MIN;
        if(arr[i][0] <= m && arr[i][1] <= n)
            ans = max(ans, 1 + solve(i + 1, arr, m - arr[i][0], n - arr[i][1], dp));
        ans = max(ans, solve(i + 1, arr, m, n, dp));
        return dp[i][m][n] = ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<vector<int>> arr(size, vector<int>(2, 0));
        vector<vector<vector<int>>> dp(size + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        for(int i = 0; i < size; i++){
            for(auto c: strs[i]){
                arr[i][c -'0'] ++;
            }
        }
        return solve(0, arr, m, n, dp);
    }
};