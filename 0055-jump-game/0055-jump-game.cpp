class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i > farthest) return false;  // if we can't reach this index
            farthest = max(farthest, i + nums[i]);
        }

        return true;
    }
};
