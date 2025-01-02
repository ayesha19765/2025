class Solution {
public:
    vector<int> leftSmaller(int n, vector<int>&arr) {
        stack<int> st;
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            if (!st.empty())
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }
    vector<int> rightSmaller(int n, vector<int>&arr) {
        stack<int> st;
        vector<int> ans(n, n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            if (!st.empty())
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        vector<int>left = leftSmaller(n, arr);
        vector<int>right = rightSmaller(n, arr);
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans,(right[i] -left[i] - 1)*arr[i]);
        }
        return ans;
    }
};