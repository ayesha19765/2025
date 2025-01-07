class Solution {
public:
    // Helper function to compute LPS array for KMP algorithm
    vector<int> kmp(const string &needle) {
        int n = needle.size();
        vector<int> lps(n, 0); // Initialize LPS array with zeros

        // Build the LPS array
        for (int i = 1, len = 0; i < n;) {
            if (needle[i] == needle[len]) {
                lps[i++] = ++len;
            } else if (len) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
        return lps;
    }

    // KMP-based substring search
    int strStr(const string &hay, const string &needle) {
        int m = hay.size(), n = needle.size();
        if (n == 0) return 0; // Edge case: empty needle
        vector<int> lps = kmp(needle); // Compute the LPS array

        // Use KMP to search for the needle in the haystack
        for (int i = 0, j = 0; i < m;) {
            if (hay[i] == needle[j]) {
                ++i, ++j;
                if (j == n) return i - j; // Found the substring
            } else if (j) {
                j = lps[j - 1]; // Use the LPS array for fallback
            } else {
                ++i;
            }
        }
        return -1; // Needle not found in haystack
    }

    // Find all substrings in the list that are contained within another string
    vector<string> stringMatching(vector<string> &words) {
        vector<string> res; // Result vector to store matching words
        int n = words.size();

        // Check each pair of words
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // If `words[i]` is a substring of `words[j]` and they are different
                if (i != j && strStr(words[j], words[i]) != -1) {
                    res.push_back(words[i]);
                    break; // No need to check further for this word
                }
            }
        }
        return res;
    }
};

/*
Time Complexity:
1. `kmp` function: O(n), where `n` is the length of the needle.
2. `strStr` function:
   - Building the LPS array: O(n).
   - Searching for the needle in the haystack: O(m), where `m` is the length of the haystack.
   - Overall complexity: O(m + n) for one call.
3. `stringMatching` function:
   - Two nested loops for comparing `words[i]` and `words[j]`: O(n^2).
   - Each `strStr` call has complexity O(m + n) where `m` and `n` are the lengths of `words[j]` and `words[i]`.
   - In the worst case, comparing every pair of words: O(n^2 * k), where `k` is the average word length.

Overall Time Complexity: O(n^2 * k).

Space Complexity:
1. `kmp` function: O(n) for the LPS array.
2. `strStr` function: O(n) for the LPS array.
3. `stringMatching` function: O(n) for the result vector (excluding input).

Overall Space Complexity: O(k), where `k` is the size of the result vector.
*/
