class MinStack {
public:
    // Stack to store values and track difference from the current minimum
    stack<long long> s;
    int mini; // Variable to store the current minimum value

    MinStack() {
        mini = -1; // Initialize mini with a default value
    }

    void push(int val) {
        if (s.empty()) {
            // If stack is empty, push 0 (difference) and set mini to the first value
            s.push(0);
            mini = val;
        } else {
            // Push the difference between the value and mini
            s.push((long long) val - mini);
            // Update the minimum value
            mini = min(mini, val);
        }
    }

    void pop() {
        // If the top of the stack is negative, update mini
        if (s.top() < 0)
            mini = mini - s.top();
        s.pop();
    }

    int top() {
        // If the top of the stack is negative, the top value is the current minimum
        if (s.top() < 0)
            return mini;
        // Otherwise, compute the top value using mini and the stored difference
        return s.top() + mini;
    }

    int getMin() {
        // Return the current minimum value
        return mini;
    }
};

/*
Time Complexity:
- `push(int val)`: O(1), constant time operations for stack push and minimum update.
- `pop()`: O(1), constant time operations for stack pop and minimum update.
- `top()`: O(1), constant time to calculate the top value.
- `getMin()`: O(1), constant time to retrieve the current minimum.

Space Complexity:
- O(N), where N is the number of elements pushed into the stack. The stack stores the difference for each element.
*/
