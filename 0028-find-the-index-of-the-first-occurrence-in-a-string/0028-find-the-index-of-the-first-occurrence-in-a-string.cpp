class Solution {
public:
    // Function to compute the LPS (Longest Prefix Suffix) array for the needle
    vector<int> kmp(string needle) {
        int n = needle.size(); 
        vector<int> lps(n, 0); // Initialize LPS array with 0
        
        // Iterate over the needle to compute LPS values
        for (int i = 1, len = 0; i < n; ) {
            if (needle[i] == needle[len]) {
                // If characters match, increment both pointers
                lps[i++] = ++len;
            } else if (len) {
                // If mismatch occurs after some matches, fallback using LPS
                len = lps[len - 1];
            } else {
                // If no match, set LPS[i] to 0 and move forward
                lps[i++] = 0;
            }
        }
        return lps; // Return the computed LPS array
    }

    // Function to find the first occurrence of needle in haystack
    int strStr(string hay, string needle) {
        int m = hay.size(); // Length of haystack
        int n = needle.size(); // Length of needle

        // Edge case: If needle is empty, return 0
        if (!n) return 0;

        // Compute the LPS array for the needle
        vector<int> lps = kmp(needle);

        // Traverse the haystack to match the needle
        for (int i = 0, j = 0; i < m; ) {
            if (hay[i] == needle[j]) {
                // If characters match, move both pointers forward
                i++, j++;
            }
            if (j == n) {
                // If the entire needle is matched, return the starting index
                return i - j;
            }
            if (i < m && hay[i] != needle[j]) {
                // If mismatch occurs after some matches
                if (j) {
                    // Use the LPS array to find the next matching position
                    j = lps[j - 1];
                } else {
                    // If no match at all, move haystack pointer forward
                    i++;
                }
            }
        }
        return -1; // If no match is found
    }
};

/*
Time Complexity:
1. Computing the LPS array in `kmp` function:
   - Takes O(n) time, where n is the length of the needle.
2. Traversing the haystack in `strStr` function:
   - Takes O(m) time, where m is the length of the haystack.
Overall time complexity: O(m + n).

Space Complexity:
- The LPS array requires O(n) space, where n is the length of the needle.
Overall space complexity: O(n).
*/
