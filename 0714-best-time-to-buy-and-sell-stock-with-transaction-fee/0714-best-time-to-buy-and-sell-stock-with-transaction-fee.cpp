class Solution {
public:
    int dp[50001][2];
    int solve(int i, bool buy, int &fee, vector<int>&prices){
        if(i == prices.size()){
            return 0;
        }

        if(dp[i][buy] != -1)
            return dp[i][buy];
        
        if(buy){
            return dp[i][buy] = max(-prices[i] + solve(i + 1, 0, fee, prices), solve(i + 1, 1, fee, prices));
        }
        else{
            return dp[i][buy] = max(prices[i] - fee + solve(i + 1, 1, fee, prices), solve(i + 1, 0, fee, prices));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp, -1, sizeof(dp));

        return solve(0, 1, fee, prices);
    }
};