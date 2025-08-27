class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // DP table to store size of largest square ending at (i, j)
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int totalSquares = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 1) {
                    // First row or first column → can only form 1x1 squares
                    if (i == 0 || j == 0)
                        dp[i][j] = 1;
                    else
                        // Square size depends on min of top, left, and top-left
                        dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});

                    // Add count of squares formed at (i, j)
                    totalSquares += dp[i][j];
                }
            }
        }

        return totalSquares;
    }
};