class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();

        // Keeps track of whether a character is already present in the stack
        vector<bool> isExist(26, false);

        // Stores the last occurrence index of every character
        vector<int> lastIndex(26);

        // Find the last occurrence of each character
        for (int i = 0; i < n; i++)
            lastIndex[s[i] - 'a'] = i;

        stack<char> st;

        for (int i = 0; i < n; i++) {

            // Skip if this character is already included in the answer
            if (isExist[s[i] - 'a'])
                continue;

            // Remove larger characters from the stack if:
            // 1. They are lexicographically greater than the current character.
            // 2. They appear again later, so we can safely add them later.
            while (!st.empty() &&
                   st.top() > s[i] &&
                   lastIndex[st.top() - 'a'] > i) {

                isExist[st.top() - 'a'] = false; // Mark as removed
                st.pop();
            }

            // Add current character to the stack
            st.push(s[i]);
            isExist[s[i] - 'a'] = true;
        }

        // Build answer from the stack (currently in reverse order)
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        // Reverse to get the correct order
        reverse(ans.begin(), ans.end());

        return ans;
    }
};