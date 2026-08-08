class Solution {
public:
    bool solve(int i, string s, unordered_map<string, bool>&mp, vector<int>&dp){
        if(i == s.size())   return true;

        if(dp[i] != -1) return dp[i];
        string str = "";
        for(int j = i; j < s.size(); j ++){
            str.push_back(s[j]);
            // cout << str << endl;
            if(mp.find(str) != mp.end())
            {
                if(solve(j + 1, s, mp, dp))
                    return  dp[i] = true;
            }
        }

        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> mp;
        vector<int>dp(s.size(), -1);
        for(int i = 0; i < wordDict.size(); i ++){
            mp[wordDict[i]] = true;
        }

        return solve(0, s, mp, dp);
    }
};