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
/*
Time Complexity
Sorting Each String:
Sorting each string takes O(LlogL), where L is the average length of strings.
For N strings, this totals to O(N⋅LlogL).

Storing in HashMap:
Inserting each string into the hash map is O(L) for each string (string comparison is based on length).
For N strings, this totals to O(N⋅L).

Iterating Over HashMap:
Extracting the grouped anagrams involves iterating over all keys and their values, which takes O(N⋅L).

Overall, the time complexity is: O(N⋅LlogL)

Space Complexity
HashMap Storage:
The hash map stores up to N keys (sorted strings) and their corresponding lists of strings. This takes  O(N⋅L) space in the worst case.

Auxiliary Space for Sorting:
Sorting requires 
O(L) space for the temporary string during each sort operation.

Total space complexity is: O(N⋅L)
*/