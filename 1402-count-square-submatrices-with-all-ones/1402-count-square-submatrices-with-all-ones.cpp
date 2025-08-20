class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int len = min(m, n);

        int ans = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                for(int start = 1; start <= min(n-j, m-i); start ++){
                    bool flag = true;
                    for(int cnt = 0; cnt < start; cnt++){
                        if(!matrix[i + cnt][j + start - 1] || !matrix[i + start - 1][j + cnt])
                        {
                            flag = false;
                            break;
                        }
                    }    
                    ans += flag; 
                    if(!flag)
                        break;
                }    
            }
        }

        return ans;
    }
};


