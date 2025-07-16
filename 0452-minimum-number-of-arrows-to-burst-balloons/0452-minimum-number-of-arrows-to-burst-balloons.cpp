class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        sort(points.begin(), points.end(), [](auto &a, auto &b) {
            return a[1] < b[1];  // sort by end
        });

        int arrows = 1; // at least one arrow needed
        int end = points[0][1];

        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > end) {
                arrows++;           // new group
                end = points[i][1]; // update end
            }
        }

        return arrows;
    }

};