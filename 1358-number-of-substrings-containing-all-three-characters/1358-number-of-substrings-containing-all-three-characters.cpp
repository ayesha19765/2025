class Solution {
public:
    int countInvalid(string &s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int freq[3] = {0};
            int distinct = 0;

            for (int j = i; j < n; j++) {
                if (++freq[s[j] - 'a'] == 1)
                    distinct++;

                if (distinct < 3)
                    ans++;
                else
                    break;
            }
        }

        return ans;
    }
    int numberOfSubstrings(string s) {
        long long n = s.size();
        return n * (n + 1) / 2 - countInvalid(s);
    }
};