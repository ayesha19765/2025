class Solution {
public:
    bool isAnagram(string s, string t) {
        // If the strings are not of the same size, they cannot be anagrams
        if(s.size() != t.size())
            return false;

        // Create a vector of 26 elements to count the occurrences of each letter
        vector<int> cnt(26,0);

        // Increment and decrement counts for each character in both strings respectively
        for(int i = 0; i < s.size(); i++){
            cnt[s[i] - 'a'] ++;
            cnt[t[i] - 'a'] --;
        }
        // Check if all counts are zero, if so, strings are anagrams, otherwise, they are not
        for(int i = 0; i < 26; i++){
            if(cnt[i])
                return 0;
        }
        return 1;
    }
};

// time - O(n)
// space - O(1)