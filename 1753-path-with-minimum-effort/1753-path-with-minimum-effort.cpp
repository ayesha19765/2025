class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<>> pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        vector<pair<int, int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};

        while (!pq.empty()) {
            auto [effort, cell] = pq.top(); pq.pop();
            int r = cell.first, c = cell.second;

            if (r == m - 1 && c == n - 1) return effort;

            for (auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nc >= 0 && nr < m && nc < n) {
                    int newEffort = max(effort, abs(heights[r][c] - heights[nr][nc]));
                    if (newEffort < dist[nr][nc]) {
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }

        return 0; // unreachable
    }
};
