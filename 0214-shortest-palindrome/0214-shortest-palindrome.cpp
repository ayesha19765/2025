class Solution {
public:
    // Function to compute the LPS (Longest Prefix Suffix) array for the KMP algorithm
    vector<int> kmp(string needle) {
        int n = needle.size();
        vector<int> lps(n, 0); // Initialize the LPS array with zeros

        // Compute the LPS values
        for (int i = 1, len = 0; i < n;) {
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

    // Function to compute the shortest palindrome by appending characters to the front
    string shortestPalindrome(string s) {
        int n = s.size();

        // Create a reversed version of the input string
        string rev(s);
        reverse(rev.begin(), rev.end());

        // Concatenate the original string, a special character '#', and the reversed string
        string s_new = s + "#" + rev;

        // Compute the LPS array for the concatenated string
        vector<int> lps = kmp(s_new);

        // The longest palindromic prefix length is given by the last value in the LPS array
        int palindromicPrefixLength = lps.back();

        // Construct the shortest palindrome by appending the necessary characters to the front
        return rev.substr(0, n - palindromicPrefixLength) + s;
    }
};

/*
Time Complexity:
1. `kmp` function: 
   - Computing the LPS array for the concatenated string `s + "#" + reverse(s)`: O(3n) = O(n), where `n` is the length of `s`.
2. `shortestPalindrome` function:
   - Reversing the string: O(n).
   - Constructing the concatenated string: O(n).
   - Computing the LPS array: O(n).
   - Constructing the final result: O(n).

Overall time complexity: O(n).

Space Complexity:
1. Space for the LPS array: O(n).
2. Space for the reversed string: O(n).
3. Space for the concatenated string: O(3n).

Overall space complexity: O(n).
*/
