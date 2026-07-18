class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini = nums[0], maxi = nums[0];

        for(int i = 1; i < nums.size(); i ++){
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }

        return gcd(mini, maxi);
    }
};