// Problem Understanding:

// You need to make two cuts (horizontal or vertical) to split the grid into three parts.
// Each rectangle should fit into one of these parts, and no parts should overlap.
// Key Idea:

// Each rectangle occupies a range on the x-axis ([startx, endx]) and y-axis ([starty, endy]).
// To split the grid into three parts, we need to find three distinct, non-overlapping intervals on either the x or y axis.
// Using Merge Intervals:

// By sorting and merging overlapping intervals (ranges), we can reduce the problem to checking how many non-overlapping sections (intervals) exist.
// If we have 3 or more merged intervals in either x or y direction, we can make the two cuts.
// Why Merge:

// Merging helps combine overlapping intervals into distinct ones, which lets us easily check if we can split the grid into three parts.
// Final Decision:

// After merging, if we get 3 or more distinct intervals in either direction (x or y), it means the cuts can be made and we return true. Otherwise, false.






class Solution {
public:
vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    if (intervals.size() <= 1) return intervals;
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
        merged.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] < merged.back()[1]) {
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        } else {
            merged.push_back(intervals[i]);
        }
    }

    return merged;
}
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> vertical;
        vector<vector<int>> horizontal;
        for(auto it: rectangles){
            vertical.push_back({it[1],it[3]}); // vertical view
            horizontal.push_back({it[0],it[2]}); // horizontal view
        }
        vector<vector<int>> mergeH= mergeIntervals(horizontal);
        vector<vector<int>> mergev= mergeIntervals(vertical);
        return mergeH.size()>=3 || mergev.size()>=3; 
    }
};