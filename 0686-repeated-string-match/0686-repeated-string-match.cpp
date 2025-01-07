class Solution {
public:
    // Function to compute the LPS (Longest Prefix Suffix) array for KMP algorithm
    vector<int> kmp(string needle) {
        int n = needle.size();
        vector<int> lps(n, 0); // Initialize LPS array with zeros

        // Compute the LPS values
        for (int i = 1, len = 0; i < n; ) {
            if (needle[i] == needle[len]) {
                // Characters match, increment both pointers and update LPS
                lps[i++] = ++len;
            } else if (len) {
                // Fallback using the LPS array
                len = lps[len - 1];
            } else {
                // No match, set LPS[i] to 0 and move forward
                lps[i++] = 0;
            }
        }
        return lps;
    }

    // Function to find the first occurrence of `needle` in `haystack`
    int strStr(string &hay, string &needle) {
        int m = hay.size(), n = needle.size();

        // Edge case: If `needle` is empty, return 0
        if (!n) return 0;

        vector<int> lps = kmp(needle); // Compute the LPS array

        // Traverse the haystack
        for (int i = 0, j = 0; i < m; ) {
            if (hay[i] == needle[j]) {
                // Characters match, move both pointers forward
                i++, j++;
            }
            if (j == n) {
                // Entire `needle` matched, return starting index
                return i - j;
            }
            if (i < m && hay[i] != needle[j]) {
                // Mismatch after partial match
                if (j) j = lps[j - 1]; // Fallback using LPS
                else i++; // No match, move haystack pointer forward
            }
        }
        return -1; // No match found
    }

    // Function to determine the minimum number of times `a` must be repeated for `b` to be a substring
    int repeatedStringMatch(string a, string b) {
        string repeated = a; // Initialize repeated string with `a`
        int count = 1; // Count of repetitions

        // Repeat `a` until its length is at least the length of `b`
        while (repeated.size() < b.size()) {
            repeated += a;
            count++;
        }

        // Check if `b` is a substring of `repeated`
        if (strStr(repeated, b) != -1) return count;

        // Check if `b` is a substring of `repeated + a`
        repeated += a;
        if (strStr(repeated, b) != -1) return count + 1;

        return -1; // If `b` is not a substring
    }
};

/*
Time Complexity:
1. `kmp` function:
   - Computing the LPS array: O(n), where n is the length of the needle.
2. `strStr` function:
   - Traversing the haystack and using the LPS array: O(m), where m is the length of the haystack.
3. `repeatedStringMatch` function:
   - Repeating `a` to form `repeated`: O(m * k), where k is the number of repetitions.
   - `strStr` calls for substring search: O(m + n).
Overall time complexity: O((m + n) * k), where m = length of `a`, n = length of `b`, and k = number of repetitions of `a`.

Space Complexity:
1. Space for the LPS array: O(n), where n is the length of the needle.
2. Additional string storage for `repeated`: O(m * k), where k is the number of repetitions.
Overall space complexity: O(n + m * k).
*/
