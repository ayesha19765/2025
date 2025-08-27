class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
       int n = mat.size();
        int m = mat[0].size();

        // DP array to store width of consecutive 1s in each row
        vector<vector<int>> width(n, vector<int>(m, 0));
        int ans = 0;

        // Step 1: Fill width DP
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    width[i][j] = (j == 0) ? 1 : width[i][j-1] + 1;
                } else {
                    width[i][j] = 0;
                }
            }
        }

        // Step 2: Count submatrices ending at (i, j)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) continue;

                int minWidth = width[i][j];
                // Go upwards from current row
                int prev = ans;
                for (int k = i; k >= 0 && width[k][j] > 0; k--) {
                    minWidth = min(minWidth, width[k][j]);
                    ans += minWidth;
                }
                // cout << ans - prev << endl;
            }
        }
        return ans;
    }
};