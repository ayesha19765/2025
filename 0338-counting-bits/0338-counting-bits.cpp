class Solution {
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1);
        if(n) ans[1] = 1;
        for(int i = 2; i <= n; i++){
            ans[i] = ans[i - (1 <<((int)log2(i)))] + 1;
        } 
        return ans;
    }
};