class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = INT_MAX, maxi = INT_MIN;


        int present[101] = {0};

        for(int i = 0; i < nums.size(); i++){
            mini = min(nums[i], mini);
            maxi = max(nums[i], maxi);

            present[nums[i]] ++;
        }

        vector<int> ans;

        for(int i = mini + 1; i < maxi; i++){
            if(!present[i]){
                ans.push_back(i);
            }
        }

        return ans;
    }
};