class Solution {
public:
    void bfs(int i, int j, int n, int m, vector<vector<char>>&board){
        board[i][j] = '#';
        
        queue<pair<int,int>> q;
        q.push({i, j});

        int dirX[] = {-1, 0, 1, 0};
        int dirY[] = {0, 1, 0, -1};

        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i < size; i++){
                auto currNode = q.front();
                q.pop();

                for(int i = 0; i < 4; i++){
                    int u = currNode.first + dirX[i], v = currNode.second + dirY[i];
         
                    
                    if(u >= 0 && u < n && v >= 0 && v < m && board[u][v] == 'O')
                    {
                        q.push({u, v});
                        board[u][v] = '#';
                    }
                }
            }
        }

        return;
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();

        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O')  bfs(i, 0, n, m, board);
            if(board[i][m - 1] == 'O') bfs(i, m - 1, n, m, board);
        }

        for(int j = 0; j < m; j++){
            if(board[0][j] == 'O') bfs(0, j, n, m, board);
            if(board[n-1][j] == 'O') bfs(n - 1, j, n, m, board);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};