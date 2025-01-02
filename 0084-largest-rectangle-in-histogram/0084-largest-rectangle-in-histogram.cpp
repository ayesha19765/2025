class Solution {
public:
    // Function to find the index of the nearest smaller element to the left for each element
    vector<int> leftSmaller(int n, vector<int>& arr) {
        stack<int> st; // Stack to store indices of elements
        vector<int> ans(n, -1); // Vector to store the result, initialized with -1

        for (int i = 0; i < n; i++) {
            // Pop elements from the stack while they are greater than or equal to arr[i]
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            // If stack is not empty, the top element is the nearest smaller element to the left
            if (!st.empty())
                ans[i] = st.top();

            // Push the current index onto the stack
            st.push(i);
        }

        return ans;
    }

    // Function to find the index of the nearest smaller element to the right for each element
    vector<int> rightSmaller(int n, vector<int>& arr) {
        stack<int> st; // Stack to store indices of elements
        vector<int> ans(n, n); // Vector to store the result, initialized with n (end of the array)

        for (int i = n - 1; i >= 0; i--) {
            // Pop elements from the stack while they are greater than or equal to arr[i]
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            // If stack is not empty, the top element is the nearest smaller element to the right
            if (!st.empty())
                ans[i] = st.top();

            // Push the current index onto the stack
            st.push(i);
        }

        return ans;
    }

    // Function to calculate the largest rectangle area in the histogram
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        
        // Get the indices of the nearest smaller elements to the left and right
        vector<int> left = leftSmaller(n, arr);
        vector<int> right = rightSmaller(n, arr);
        
        int ans = 0; // Variable to store the maximum area

        // Calculate the area for each element, considering the distance between the left and right smaller elements
        for (int i = 0; i < n; i++) {
            ans = max(ans, (right[i] - left[i] - 1) * arr[i]);
        }

        return ans;
    }
};

/*
Time Complexity:
- O(n), for each of the leftSmaller and rightSmaller functions, where n is the number of elements in the array. Each element is pushed and popped from the stack once.
- The largestRectangleArea function iterates through the array once, so the overall time complexity is O(n).

Space Complexity:
- O(n), for the stack and the result vectors used in the leftSmaller and rightSmaller functions.
*/
