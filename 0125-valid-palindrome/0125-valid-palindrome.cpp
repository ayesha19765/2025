class Solution {
public:
    bool isPalindrome(string s) {
        // Convert all characters in the string to lowercase
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        int i = 0, j = s.size() - 1;

        // Two-pointer approach to check if the string is a palindrome
        while (i < j) {
            char ch1 = s[i], ch2 = s[j];

            // Skip non-alphanumeric characters from the left
            if (!((ch1 >= 'a' && ch1 <= 'z') || (ch1 >= '0' && ch1 <= '9'))) {
                i++;
                continue;
            }

            // Skip non-alphanumeric characters from the right
            if (!((ch2 >= 'a' && ch2 <= 'z') || (ch2 >= '0' && ch2 <= '9'))) {
                j--;
                continue;
            }

            // Check if characters at the two pointers match
            if (ch1 != ch2)  
                return false;

            // Move the pointers closer to each other
            i++;
            j--;
        }

        // If all characters match, the string is a palindrome
        return true;
    }
};

/*
### Explanation:
1. **Purpose**: This function checks if a given string `s` is a palindrome, considering only alphanumeric characters and ignoring cases.
2. **Steps**:
   - Use `transform()` to convert the string to lowercase for case insensitivity.
   - Use a two-pointer approach:
     - Increment the `i` pointer if the current character is not alphanumeric.
     - Decrement the `j` pointer if the current character is not alphanumeric.
     - If both characters at `i` and `j` are valid and do not match, return `false`.
   - Continue until the pointers cross each other.
3. **Return**: If no mismatch is found, the string is a palindrome.

### Time Complexity:
- **O(n)**: We process each character of the string at most twice (once for case conversion and once during the two-pointer traversal).

### Space Complexity:
- **O(1)**: The operation is performed in-place, using a constant amount of extra memory.
*/
