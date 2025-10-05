class Solution {
public:
    int m, n;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));

        // Perform BFS from Pacific (top and left)
        for (int i = 0; i < m; i++) bfs(i, 0, heights, pacific);
        for (int j = 0; j < n; j++) bfs(0, j, heights, pacific);

        // Perform BFS from Atlantic (bottom and right)
        for (int i = 0; i < m; i++) bfs(i, n - 1, heights, atlantic);
        for (int j = 0; j < n; j++) bfs(m - 1, j, heights, atlantic);

        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }

    void bfs(int i, int j, vector<vector<int>>& heights, vector<vector<int>>& ocean) {
        queue<pair<int, int>> q;
        q.push({i, j});
        ocean[i][j] = 1;

        vector<int> dirX = {-1, 0, 1, 0};
        vector<int> dirY = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + dirX[d];
                int ny = y + dirY[d];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n &&
                    heights[nx][ny] >= heights[x][y] && ocean[nx][ny] == 0) {
                    ocean[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
};
