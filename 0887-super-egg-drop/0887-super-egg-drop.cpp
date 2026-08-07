class Solution {
public:
    int solve(int k, int n, vector<vector<int>>& dp) {

        if (n == 0 || n == 1)
            return n;

        if (k == 1)
            return n;

        if (dp[k][n] != -1)
            return dp[k][n];

        int ans = INT_MAX;

        int low = 1;
        int high = n;

        while (low <= high) {

            int x = low + (high - low) / 2;

            int breakCase = solve(k - 1, x - 1, dp);
            int surviveCase = solve(k, n - x, dp);

            int worst = 1 + max(breakCase, surviveCase);

            ans = min(ans, worst);

            // breakCase is smaller
            // Need to go higher
            if (breakCase < surviveCase) {
                low = x + 1;
            }
            else {
                // breakCase is larger
                // Need to go lower
                high = x - 1;
            }
        }

        return dp[k][n] = ans;
    }

    int superEggDrop(int k, int n) {

        vector<vector<int>> dp(
            k + 1,
            vector<int>(n + 1, -1)
        );

        return solve(k, n, dp);
    }
};