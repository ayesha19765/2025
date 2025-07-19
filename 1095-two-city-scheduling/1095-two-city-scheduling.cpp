class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        return (a[0] - a[1]) < (b[0] - b[1]);
    }

    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), comp); // custom comparator

        int n = costs.size() / 2;
        int ans = 0;

        // First n people to city A, rest to city B
        for (int i = 0; i < costs.size(); ++i) {
            if (i < n)
                ans += costs[i][0]; // city A
            else
                ans += costs[i][1]; // city B
        }

        return ans;
    }
};
