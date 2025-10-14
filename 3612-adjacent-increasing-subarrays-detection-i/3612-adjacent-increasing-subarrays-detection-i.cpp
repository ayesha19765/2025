class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
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
        
        
        for (int i = 0; i < n - 1; ++i) {
            if (end[i] >= k && start[i + 1] >= k) {
                return true;
            }
        }
        
        return false;  
    }
};
