class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        int n = s.size();
        vector<string> ans;
        ans.push_back("");

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            char current = s[i];

            bool isAlpha = isalpha(current);

            for (auto &str : ans) {
                temp.push_back(str + (char)tolower(current));

                if (isAlpha) {
                    temp.push_back(str + (char)toupper(current));
                }
            }

            ans = temp;
        }

        return ans;
    }
};
