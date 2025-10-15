class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        // create a vector end
        // end[i] -> denotes the max length of increasing subarray that ends at nums[i]

        // create another vector start
        // start[i] -> denotes the max length of increasing subarray that starts at nums[i]

        // return // max val of min(end[i], start[i + 1])

        int n = nums.size();
        vector<int> end(n, 1), start(n, 1);
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                end[i] = end[i - 1] + 1;
            }
        }
        
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                start[i] = start[i + 1] + 1;
            }
        }
        
        int maxK = 0;
        for (int i = 0; i < n - 1; ++i) {
            maxK = max(maxK, min(end[i], start[i + 1]));
        }
        
        return maxK;
    }
};