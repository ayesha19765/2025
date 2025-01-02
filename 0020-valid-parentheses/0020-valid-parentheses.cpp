class Solution
{
public:
    bool isValid(string s)
    {
        // Stack to keep track of opening brackets
        stack<char> s1;

        // Iterate through the string
        for (int i = 0; i < s.size(); i++)
        {
            // Push opening brackets onto the stack
            if ((s[i] == '(') || (s[i] == '[') || (s[i] == '{'))
                s1.push(s[i]);
            else
            {
                // If stack is empty, there's no matching opening bracket
                if (s1.empty())
                    return false;

                // Check the top of the stack for matching bracket
                char op = s1.top();
                if (((s[i] == '}') && (op == '{')) || 
                    ((s[i] == ')') && (op == '(')) || 
                    ((s[i] == ']') && (op == '[')))
                    s1.pop(); // Pop the stack if the brackets match
                else
                    return false; // Mismatch found
            }
        }

        // If the stack is empty, all brackets are valid and matched
        return s1.empty();
    }
};

/*
Time Complexity:
- The algorithm iterates through the string once, making it O(N), where N is the length of the string.

Space Complexity:
- The stack is used to store opening brackets. In the worst case (all opening brackets), the space complexity is O(N).
*/
