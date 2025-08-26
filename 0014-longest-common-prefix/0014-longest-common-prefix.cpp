class Solution {
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        sort(strs.begin(), strs.end());
        
        int first = 0, last = strs.size() - 1;
        int len = 0, i = 0;
        while(i < strs[first].size() && i < strs[last].size() && strs[first][len] == strs[last][len]){
            i++;
            len++;
        }

        return strs[first].substr(0, len);
    }
};