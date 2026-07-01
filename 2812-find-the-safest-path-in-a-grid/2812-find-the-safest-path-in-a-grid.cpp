class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int helper(vector<vector<int>>& minD) {
        int n = minD.size();

        priority_queue<tuple<int, int, int>> pq;
        vector<vector<int>> best(n, vector<int>(n, -1));

        pq.push({minD[0][0], 0, 0});
        best[0][0] = minD[0][0];

        while (!pq.empty()) {
            auto [safe, x, y] = pq.top();
            pq.pop();

            if (x == n - 1 && y == n - 1)
                return safe;

            if (safe < best[x][y])
                continue;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    int newSafe = min(safe, minD[nx][ny]);

                    if (newSafe > best[nx][ny]) {
                        best[nx][ny] = newSafe;
                        pq.push({newSafe, nx, ny});
                    }
                }
            }
        }

        return 0;
    }

    void bfs(vector<vector<int>>& minD, vector<vector<int>>& grid) {
        int n = grid.size();

        queue<pair<int, int>> q;

        // Push all thieves
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    minD[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                    minD[nx][ny] == INT_MAX) {

                    minD[nx][ny] = minD[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> minD(n, vector<int>(n, INT_MAX));

        // Step 1: Multi-source BFS
        bfs(minD, grid);

        // Step 2: Max-heap Dijkstra
        return helper(minD);
    }
};