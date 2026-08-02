class Solution {
public:
    int solve(int s, int e, vector<int>& piles, vector<vector<int>>& dp) {
        if(s > e) {
            return 0;
        }

        if(dp[s][e] != -1) {
            return dp[s][e];
        }

        int totalSum = 0;
        for(int i = s; i <= e; i++) {
            totalSum += piles[i];
        }
        
        int op1 = totalSum - solve(s + 1, e, piles, dp);
        int op2 = totalSum - solve(s, e - 1, piles, dp);
        return dp[s][e] = max(op1, op2);
    }

    bool stoneGame(vector<int>& piles) {
        int totalSum = 0;
        for(int i = 0; i < piles.size(); i++) {
            totalSum += piles[i];
        }

        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        if(solve(0, n - 1, piles, dp) > totalSum / 2)
            return true;
        return false;
    }
};
