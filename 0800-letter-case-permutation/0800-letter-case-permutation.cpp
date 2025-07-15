class Solution {
public:
    // Helper function that recursively generates permutations
    void backtrack(string &s, int index, string &current, vector<string> &result) {
        // Base Case: If we've processed all characters, store the current permutation
        if (index == s.size()) {
            result.push_back(current);
            return;
        }

        char c = s[index];

        // Case 1: Keep the character as it is (either digit or original case letter)
        current.push_back(c);                  // Add current character to the working string
        backtrack(s, index + 1, current, result);  // Move to the next character
        current.pop_back();                    // Backtrack by removing the last character

        // Case 2: If the character is a letter, change its case and explore that path
        if (isalpha(c)) {
            // Flip the case: lowercase -> uppercase or uppercase -> lowercase
            current.push_back(islower(c) ? toupper(c) : tolower(c));
            backtrack(s, index + 1, current, result);  // Move to the next character
            current.pop_back();                        // Backtrack
        }
    }

    // Main function that starts the backtracking
    vector<string> letterCasePermutation(string s) {
        vector<string> result;  // To store all valid permutations
        string current;         // Temporary string used to build each permutation
        backtrack(s, 0, current, result);  // Start from index 0
        return result;         // Return the final list of permutations
    }
};
