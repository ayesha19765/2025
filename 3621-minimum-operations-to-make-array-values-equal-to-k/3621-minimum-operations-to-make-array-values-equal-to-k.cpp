class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i: nums){
            mp[i]++;
        }

        for(int i = 1; i < k; i ++){
            if(mp.find(i) != mp.end())
                return -1;
        }

        return mp.size() - (mp[k] > 0) ;
    }
};