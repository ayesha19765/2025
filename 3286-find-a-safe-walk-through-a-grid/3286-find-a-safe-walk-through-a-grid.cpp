class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        priority_queue< tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        int  n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int dirX[] = {-1, 0, +1, 0};
        int dirY[] = {0, +1, 0, -1};

        pq.push({grid[0][0], 0, 0});
        // vis[0][0] = 1;
        while(!pq.empty()){
            auto [dist, x, y] = pq.top();
            pq.pop();

            if (vis[x][y])
                continue;

            vis[x][y] = true;
            if(x == n - 1 && y == m - 1){
                
                if(dist < health)
                    return true;

                return false;
            }
            
            for(int i = 0; i < 4; i++){
                int newX = x + dirX[i];
                int newY = y + dirY[i];

                if(newX >= 0 && newX < n && newY >= 0 && newY < m && !vis[newX][newY]){
                    pq.push({dist + grid[newX][newY], newX, newY});
                    // vis[newX][newY] = 1;
                }
            }
        }

        return false;
    }
};