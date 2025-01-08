class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ans = 1, up = 1;  // Initialize variables: ans to track maximum length, up for tracking the current sequence length
        bool flagUp = 1;       // Flag to track the direction of the sequence (1 for up, 0 for down)

        // Iterate through the array starting from the second element
        for(int i = 1; i < arr.size(); i++) {
            // If current element is greater than previous element, it's an 'up' transition
            if(arr[i] > arr[i - 1]) {
                // If the previous direction was 'up', extend the current 'up' sequence; else start a new 'up' sequence of length 2
                up = (flagUp) ? up + 1 : 2;
                flagUp = 0;  // Mark the current direction as 'down'
            } 
            // If current element is less than previous element, it's a 'down' transition
            else if(arr[i] < arr[i - 1]) {
                // If the previous direction was 'down', extend the current 'down' sequence; else start a new 'down' sequence of length 2
                up = (!flagUp) ? up + 1 : 2;
                flagUp = 1;  // Mark the current direction as 'up'
            } 
            // If current element equals the previous element, reset the sequence
            else {
                up = 1;  // Reset to a sequence of length 1
                flagUp = 1;  // Set to 'up' to start a new sequence
            }
            // Keep track of the maximum turbulent subarray length
            ans = max(ans, up);
        }

        return ans;  // Return the maximum length of a turbulent subarray
    }
};

/*
### Explanation:
- We iterate through the array and use a flag to track whether the current transition is 'up' or 'down'.
- If the current element is greater than the previous one, it represents an 'up' transition. If the previous one was also 'up', we extend the sequence. Otherwise, we start a new 'up' sequence.
- If the current element is smaller than the previous one, it represents a 'down' transition. Similarly, if the previous one was 'down', we extend the sequence. Otherwise, we start a new 'down' sequence.
- If two consecutive elements are equal, we reset the sequence as turbulence requires alternating directions.

### Time Complexity:
- The algorithm iterates through the array once, so the time complexity is O(n), where n is the size of the array.

### Space Complexity:
- The space complexity is O(1), as the solution only uses a few integer variables to track the state and does not require any additional space dependent on the input size.
*/
