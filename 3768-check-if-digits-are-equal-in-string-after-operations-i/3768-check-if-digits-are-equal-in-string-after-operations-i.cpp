class Solution {
public:
    bool hasSameDigits(const string &s) {
        auto binomMod5 = [](int n, int r) -> int {
            int table[5][5] = {
                {1,0,0,0,0},
                {1,1,0,0,0},
                {1,2,1,0,0},
                {1,3,3,1,0},
                {1,4,1,4,1}
            };
            int res = 1;
            while (n || r) {
                int n_digit = n % 5;
                int r_digit = r % 5;
                if (r_digit > n_digit) return 0;
                res = (res * table[n_digit][r_digit]) % 5;
                n /= 5;
                r /= 5;
            }
            return res;
        };

        auto binomMod10 = [&](int k, int j) -> int {
            int r2 = ((j & ~k) == 0) ? 1 : 0;
            int r5 = binomMod5(k, j);
            return (5 * r2 + 6 * r5) % 10;
        };

        int n = s.size();
        int k = n - 2;
        int x = 0, y = 0;

        for (int j = 0; j <= k; j++) {
            int c = binomMod10(k, j);
            x = (x + c * (s[j] - '0')) % 10;
            y = (y + c * (s[j + 1] - '0')) % 10;
        }

        return x == y;
    }
};
