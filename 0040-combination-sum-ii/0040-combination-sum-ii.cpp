class Solution {
public:
    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& temp, int start) {
        if (target == 0) {
            res.push_back(temp); // Found a valid combination
            return;
        }
        if (target < 0) return; // Exceeded target
        
        for (int i = start; i < candidates.size(); ++i) {
            if(i != start && candidates[i] == candidates[i - 1])    continue;
            temp.push_back(candidates[i]);          // Choose
            backtrack(candidates, target - candidates[i], res, temp, i + 1); // i+1, because we can't reuse same element
            temp.pop_back();                        // Backtrack
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(candidates, target, res, temp, 0);
        return res;
    }
};
