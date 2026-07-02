class Solution {
public:
    void dfs(int i, vector<vector<int>> &isConnected, vector<bool> &visited)
    {
        // cout<<i<<endl;
        visited[i] = 1;
        for (int j = 0; j < isConnected[i].size(); j++)
        {
            if (j != i && isConnected[i][j] == 1 &&visited[j] == false)
            {
                dfs(j, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int ans = 0;
        int v = isConnected.size();
        vector<bool> visited(v);
        for (int i = 0; i < v; i++)
        {
            if (visited[i] == false)
            {
                // cout<<i<<endl;
                ans++;
                // cout<<"calling"<<i<<endl;
                dfs(i, isConnected, visited);
            }
        }
        return ans;
    }
};