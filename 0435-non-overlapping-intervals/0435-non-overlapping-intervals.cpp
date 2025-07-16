class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
        return a[1] < b[1];  // sort by end time
    });

    int end = INT_MIN, count = 0;
    for (auto &i : intervals) {
        if (i[0] >= end) {       // no overlap
            end = i[1];
            count++;
        }
    }
    return intervals.size() - count;  // remove the rest
}

};