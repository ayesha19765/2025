class Solution {
public:
    string minWindow(string s, string t) {
        // Frequency array to count characters in t
        int cnt[128] = {0};

        // Count frequency of each character in string t
        for (auto ch : t) cnt[ch]++;

        int i = 0, j = 0, minStart = 0, ans = INT_MAX;
        // Initialize the number of characters in t that are yet to be found in the window
        int chNotFound = t.size(), n = s.size();

        while (j < n) {
            // If the character in s[j] is needed, decrement chNotFound
            if (cnt[s[j]] > 0) {
                chNotFound--;
            }
            // Decrease the count for the current character
            cnt[s[j]]--;

            // Once all characters are found (chNotFound == 0)
            while (chNotFound == 0) {
                // If the current window size is smaller than the previous smallest, update minStart and ans
                if ((j - i + 1) < ans) {
                    minStart = i;
                    ans = j - i + 1;
                }

                // Move the left pointer i to the right
                cnt[s[i]]++;

                // If moving i results in missing a character, increment chNotFound
                if (cnt[s[i]] > 0) {
                    chNotFound++;
                }

                i++;  // Shrink the window from the left
            }

            j++;  // Expand the window by moving j to the right
        }

        // Return the smallest window as a substring of s
        return s.substr(minStart, (ans == INT_MAX ? 0 : ans));
    }
};

/*
Time Complexity:
- O(n), where n is the length of string s. We iterate over s with the pointers i and j, and for each character in s, we adjust the window. Both i and j only move forward, so they each traverse the string at most once. Therefore, the overall time complexity is O(n).
  
Space Complexity:
- O(1) (constant space) because the frequency array `cnt` has a fixed size of 128 (for ASCII characters). It does not grow with the input size, so the space complexity is O(1).
*/
