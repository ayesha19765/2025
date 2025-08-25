#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        
        int n = mat.size();
        int m = mat[0].size();
        
        // Loop through all possible sums of indices
        for (int sum = 0; sum < n + m - 1; sum++) {
            if (sum % 2 == 0) {
                // Traverse upwards
                int i = min(sum, n - 1);
                int j = sum - i;
                while (i >= 0 && j < m) {
                    ans.push_back(mat[i][j]);
                    i--;
                    j++;
                }
            } else {
                // Traverse downwards
                int j = min(sum, m - 1);
                int i = sum - j;
                while (j >= 0 && i < n) {
                    ans.push_back(mat[i][j]);
                    i++;
                    j--;
                }
            }
        }
        return ans;
    }
};
