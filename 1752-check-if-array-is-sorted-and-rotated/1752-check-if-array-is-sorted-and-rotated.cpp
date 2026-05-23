class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        bool flag = false;

        for(int i = 1; i < nums.size(); i ++){
            if(nums[i] < nums[i - 1] ){
                if(flag)
                    return false;
                flag = true;
            }
        }

        if(flag){
            if(nums[n - 1] > nums[0])
                return false;
        }

        return true;
    }
};