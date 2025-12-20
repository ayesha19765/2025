class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cnt = 0;

        int n = strs.size();
        int len = strs[0].size();

        for(int i = 0; i < len; i++){
            int prev = strs[0][i];
            for(int j = 1; j < n; j++){
                if(strs[j][i] < prev)
                {
                    cnt ++;
                    break;
                }
                prev = strs[j][i];
            }
        }

        return cnt;
    }
};