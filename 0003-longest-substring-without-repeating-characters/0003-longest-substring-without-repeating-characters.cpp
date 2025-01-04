class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        // `cnt` keeps track of the frequency of characters in the current substring
        unordered_map<char, int> cnt;

        // `i` is the start pointer, `j` is the end pointer of the sliding window
        int i = 0, j = 0, ans = 0;

        // Iterate through the string with `j` as the end pointer
        while (j < str.size()) {
            // Include the current character in the sliding window
            cnt[str[j]]++;

            // If there is a duplicate character in the window
            while (cnt[str[j]] > 1) {
                // Shrink the window from the start
                cnt[str[i]]--;
                i++;
            }

            // Update the maximum length of the substring without repeating characters
            ans = max(ans, j - i + 1);

            // Move the end pointer to the next character
            j++;
        }

        // Return the length of the longest substring without repeating characters
        return ans;
    }
};

/*
Time Complexity:
- O(n): We traverse the string with the `j` pointer once, and the `i` pointer may traverse each character at most once, resulting in a linear time complexity.

Space Complexity:
- O(k): Where `k` is the size of the character set. For example, in the worst case, for ASCII characters, `k = 128`. The `cnt` map stores at most `k` unique characters.
*/
