class Solution {
public:
    // Function to construct the Longest Prefix Suffix (LPS) array for the given pattern (needle)
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
    
    string longestPrefix(string s) {
        vector<int> ans = kmp(s);
        
        // The longest prefix that is also a suffix has length stored at the last position of the lps array.
        int maxi = ans.back();
        
        // Extract the prefix of length 'maxi'.
        string res = s.substr(0, maxi);
        
        return res;
    }
 
};