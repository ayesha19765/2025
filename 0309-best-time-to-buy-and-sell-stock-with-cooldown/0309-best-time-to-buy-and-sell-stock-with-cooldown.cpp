class Solution {
public:
    int dp[5001][3];
    int solve(int i, int buy, vector<int>& prices){
        if(i == prices.size())
            return 0;

        if(dp[i][buy] != -1)
            return dp[i][buy];
        
        if(buy == 2){// can Buy
            return dp[i][buy] = max(-prices[i] + solve(i + 1, 1, prices), solve(i + 1, 2, prices));
        }else if(buy == 1){ // cannot buy but sell
            return dp[i][buy] = max(prices[i] + solve(i + 1, 0, prices), solve(i + 1, 1, prices));
        }else{ // cannot buy but sell i.e cooldown
            return dp[i][buy] = solve(i + 1, 2, prices);
        }
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));

        return solve(0, 2, prices);
    }
};