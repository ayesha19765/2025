class Solution {
public:
    string shortestBeautifulSubstring(string str, int k) {
        int n = str.size();
        int left = 0;
        int ones = 0;
        int mini = INT_MAX;
        string ans = "";

        for (int right = 0; right < n; right++) {

            if (str[right] == '1')
                ones++;

            while (ones > k) {
                if (str[left] == '1')
                    ones--;
                left++;
            }

            if (ones == k) {

                // Remove leading zeroes because they make
                // the substring unnecessarily long
                while (left <= right && str[left] == '0')
                    left++;

                int len = right - left + 1;

                if (len < mini ||
                    (len == mini && str.substr(left, len) < ans)) {

                    mini = len;
                    ans = str.substr(left, len);
                }
            }
        }

        return ans;
    }
};