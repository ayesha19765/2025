class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);

        vector<int> inDegree(n, 0);

        for(int u = 0; u < n; u++){
            for(auto v: graph[u]){
                adj[v].push_back(u);
                inDegree[u] ++;
            }
        }

        queue<int> q;

        for(int i = 0; i < n; i ++){
            if(inDegree[i] == 0)
            {
                q.push(i);
                inDegree[i] = -1;
            }
        }

        vector<int> ans;

        while(!q.empty()){
            int currNode = q.front();
            q.pop();
            ans.push_back(currNode);

            for(auto neigh: adj[currNode]){
                inDegree[neigh] --;

                if(inDegree[neigh] == 0){
                    q.push(neigh);
                    inDegree[neigh] = -1;
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};