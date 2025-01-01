class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Resultant 2D vector to store groups of anagrams
        vector<vector<string>> res;

        // Unordered map to group anagrams using their sorted string as the key
        unordered_map<string, vector<string>> m;

        // Traverse each string in the input array
        for(auto s: strs) {
            string tmp = s;               // Copy the current string
            sort(tmp.begin(), tmp.end()); // Sort the string to use as a key
            m[tmp].push_back(s);          // Group the original string in the map
        }

        // Collect all groups of anagrams from the map
        for(auto x: m) {
            res.push_back(x.second); // Add the grouped anagrams to the result
        }

        return res; // Return the final groups of anagrams
    }
};
