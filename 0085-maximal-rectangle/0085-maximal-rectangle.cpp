class Solution {
public:
    // Function to calculate largest rectangle in histogram
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            // For the last index, use height 0 to clear the stack
            int currHeight = (i == n) ? 0 : heights[i];

            // Pop from stack until current height >= top of stack height
            while (!st.empty() && currHeight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();

                // Width = distance between current index and index before top
                int w = st.empty() ? i : i - st.top() - 1;

                maxArea = max(maxArea, h * w);
            }
            st.push(i);
        }
        return maxArea;
    }

    // Main function to calculate maximal rectangle
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxRectangle = 0;

        // Process each row
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // If cell has '1', increase height, else reset to 0
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }

            // Find largest rectangle in current histogram
            maxRectangle = max(maxRectangle, largestRectangleArea(heights));
        }

        return maxRectangle;
    }
};
