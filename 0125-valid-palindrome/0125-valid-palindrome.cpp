class Solution {
public:
    bool isPalindrome(string s) {
        // Initialize two pointers, one at the beginning and one at the end
        int i = 0, j = s.size() - 1;

        // Loop until the two pointers meet
        while(i < j) {
            int val1 = 0, val2 = 0;

            // Process the character at position i
            if(s[i] >=  'A' && s[i] <= 'Z')
                val1 = s[i] + 32; // Convert to lowercase if uppercase
            else if(s[i] >=  'a' && s[i] <= 'z')
                val1 = s[i]; // Keep the character if it's already lowercase
            else if(s[i] >=  '0' && s[i] <= '9')
                val1 = s[i]; // Keep the digit
            else {
                i++; // Skip non-alphabetical characters
                continue;
            }

            // Process the character at position j
            if(s[j] >=  'A' && s[j] <= 'Z')
                val2 = s[j] + 32; // Convert to lowercase if uppercase
            else if(s[j] >=  'a' && s[j] <= 'z')
                val2 = s[j]; // Keep the character if it's already lowercase
            else if(s[j] >=  '0' && s[j] <= '9')
                val2 = s[j]; // Keep the digit
            else {
                j--; // Skip non-alphabetical characters
                continue;
            }

            // If the characters don't match, return false
            if(val1 != val2) return false;

            // Move both pointers towards the center
            i++, j--;
        }

        // Return true if the entire string is a palindrome
        return true;
    }
};

/*
Time Complexity:
- We iterate through the string once with two pointers, checking each character. 
- The time complexity is O(N), where N is the length of the string.

Space Complexity:
- We use a constant amount of extra space for the two variables (val1, val2), so the space complexity is O(1).
*/
