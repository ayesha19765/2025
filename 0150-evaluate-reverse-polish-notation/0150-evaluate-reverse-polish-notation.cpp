class Solution {
public:
    int evalRPN(vector<string>& t) {
        // Stack to evaluate the Reverse Polish Notation
        stack<int> s;

        // Iterate through the tokens
        for (int i = 0; i < t.size(); i++) {
            // Check if the token is an operator
            if (t[i].size() == 1 && (t[i][0] == '-' || t[i][0] == '*' || t[i][0] == '/' || t[i][0] == '+')) {
                int l = s.top(); // Right operand
                s.pop();
                int r = s.top(); // Left operand
                s.pop();
                
                // Perform the operation and push the result back onto the stack
                if (t[i][0] == '+')
                    s.push(r + l);
                else if (t[i][0] == '-')
                    s.push(r - l);
                else if (t[i][0] == '*')
                    s.push(r * l);
                else if (t[i][0] == '/')
                    s.push(r / l);
            } else {
                // If the token is a number, convert it to an integer and push onto the stack
                s.push(stoi(t[i]));
            }
        }
        
        // The result is the only value left on the stack
        return s.top();
    }
};

/*
Time Complexity:
- O(N), where N is the number of tokens in the input vector. Each token is processed once.

Space Complexity:
- O(N), for the stack used to store operands during evaluation.
*/
