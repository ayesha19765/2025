class Solution {
public:
    bool isPalindrome(const string &s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> reversedWordMap;
        vector<vector<int>> result;

        // Store reversed word -> index
        for (int i = 0; i < words.size(); i++) {
            string reversed = words[i];
            reverse(reversed.begin(), reversed.end());
            reversedWordMap[reversed] = i;
        }

        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            int len = word.length();

            for (int j = 0; j <= len; j++) {
                string prefix = word.substr(0, j);
                string suffix = word.substr(j);

                // If prefix is palindrome, look for reversed suffix
                if (isPalindrome(word, 0, j - 1)) {
                    if (reversedWordMap.count(suffix) && reversedWordMap[suffix] != i) {
                        result.push_back({reversedWordMap[suffix], i});
                    }
                }

                // If suffix is palindrome, look for reversed prefix
                // j < len to avoid duplicates (when prefix and suffix both are "")
                if (j < len && isPalindrome(word, j, len - 1)) {
                    if (reversedWordMap.count(prefix) && reversedWordMap[prefix] != i) {
                        result.push_back({i, reversedWordMap[prefix]});
                    }
                }
            }
        }

        return result;
    }
};
