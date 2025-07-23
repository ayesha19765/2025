class Solution {
public:
    void backtrack(vector<int>& nums, vector<bool>& visited, 
                   vector<int>& temp, vector<vector<int>>& res) {
        if (temp.size() == nums.size()) {
            res.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i]) continue;

            visited[i] = true;
            temp.push_back(nums[i]);

            backtrack(nums, visited, temp, res);

            // Backtrack
            visited[i] = false;
            temp.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> visited(nums.size(), false);
        backtrack(nums, visited, temp, res);
        return res;
    }
};
