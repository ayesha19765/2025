class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0, end = 0, ans = 0, cnt = 0;
        while(end < nums.size()){
            if(nums[end] == 0)
            {
                while(cnt >= k){
                    if(nums[start] == 0)
                        cnt --;
                    start ++;
                }
                cnt ++;
            }
            ans = max(ans, end - start + 1);
            end ++;
        }
        return ans;
    }
};