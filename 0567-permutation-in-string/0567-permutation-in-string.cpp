// Major logic: strX is a Permutation of strY ==> just freqs of strX and strY need to be equal
class Solution {
    // Helper function to check if two frequency vectors are equal
    bool areVectorsEqual(vector<int> a, vector<int> b) {
        for (int i = 0; i < 26; i++) {  // There are 26 letters in the alphabet
            if (a[i] != b[i]) return false;  // If frequencies don't match, return false
        }
        return true;  // Vectors are equal, return true
    }

public:
    bool checkInclusion(string s1, string s2) {
        // If the length of s1 is greater than s2, return false
        if (s2.size() < s1.size()) return false;

        // Frequency array to store character counts for s1
        vector<int> freqS1(26, 0);
        for (char c : s1) freqS1[c - 'a']++;  // Count characters in s1
        
        // Frequency array to store character counts for the current window in s2
        vector<int> freqS2(26, 0);

        int i = 0, j = 0;  // Sliding window pointers
        while (j < s2.size()) {
            // Expand the window by adding the character at s2[j]
            freqS2[s2[j] - 'a']++;

            // When the window size matches the size of s1
            if (j - i + 1 == s1.size()) {
                // Check if the frequency vectors match (i.e., if the current window is a permutation of s1)
                if (areVectorsEqual(freqS1, freqS2)) return true;
            }

            // If the window size is less than s1's size, expand the window by moving j
            if (j - i + 1 < s1.size()) {
                j++;
            }
            else {
                // Otherwise, shrink the window from the left by moving i
                freqS2[s2[i] - 'a']--;  // Decrement the frequency of the character at s2[i]
                i++;  // Move the start of the window
                j++;  // Expand the window
            }
        }

        // If no valid permutation is found, return false
        return false;
    }
};

/*
Time Complexity:
- O(n), where n is the length of s2. We traverse the string s2 once, and for each window, we compare the frequency vectors, which takes constant time since they have a fixed size of 26.
- In total, the time complexity is O(n), where n is the length of s2.

Space Complexity:
- O(1) (constant space), as the frequency arrays `freqS1` and `freqS2` have a fixed size of 26 (for the 26 letters of the alphabet).
- The space complexity is O(1) because the space does not scale with the input size.
*/
