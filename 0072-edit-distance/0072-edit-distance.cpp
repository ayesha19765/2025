class Solution {
public:
    int solve(int i, int j, string word1, string word2, vector<vector<int>> &dp){
        if(i == word1.size() || j == word2.size()){
            return (word1.size() - i) + (word2.size() - j);
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(word1[i] == word2[j]){
            return dp[i][j] = solve(i + 1, j + 1, word1, word2, dp);
        }

        int op1 = 1 + solve(i, j + 1, word1, word2, dp);
        int op2 = 1 + solve(i + 1, j, word1, word2, dp);
        int op3 = 1 + solve(i + 1, j + 1, word1, word2, dp);

        return dp[i][j] = min({op1, op2, op3});
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int> (word2.size(), -1));
        return solve(0, 0, word1, word2, dp);
    }
};