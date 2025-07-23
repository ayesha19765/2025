class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.empty()) return res;

        // Step 1: Sort intervals by start time
        sort(intervals.begin(), intervals.end());

        // Step 2: Merge
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= res.back()[1]) {
                // Overlap case: merge
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            } else {
                // No overlap: push new interval
                res.push_back(intervals[i]);
            }
        }
        return res;
    }

};