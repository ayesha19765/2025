class Solution {
public:
    // Helper function to generate valid parenthesis combinations
    void getAns(int open, int closed, int n, vector<string> &ans, string &s) {
        // If the current string has 2*n characters, it's a valid combination
        if (s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }

        // If the number of open brackets used is less than 'n', add an open bracket
        if (open < n) {
            s.push_back('(');
            getAns(open + 1, closed, n, ans, s);
            s.pop_back(); // Backtrack
        }

        // If the number of closed brackets is less than open brackets, add a closed bracket
        if (closed < open) {
            s.push_back(')');
            getAns(open, closed + 1, n, ans, s);
            s.pop_back(); // Backtrack
        }
    }

    // Main function to generate all combinations of well-formed parentheses
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        getAns(0, 0, n, ans, s); // Start with 0 open and closed brackets
        return ans;
    }
};

/*
Time Complexity:(IMPPPP)
- O(4^n / √n), derived from the Catalan number formula. This represents the total number of valid combinations.

Space Complexity:
- O(n), for the recursive call stack and the string `s` used during backtracking.
*/
