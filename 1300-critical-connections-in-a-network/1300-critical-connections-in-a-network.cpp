#include <bits/stdc++.h>
using namespace std;

class Solution {
    int timer = 0;  // To keep track of discovery times
    vector<vector<int>> bridges; // Stores the critical connections

    // Depth First Search to find bridges (critical connections)
    void dfs(int node, int parent, vector<int> adj[], vector<int> &visited,
             vector<int> &discTime, vector<int> &lowTime) {

        visited[node] = 1;
        discTime[node] = lowTime[node] = timer++; // Set discovery & low time

        // Go through all connected nodes
        for (int neighbor : adj[node]) {

            // Skip the edge leading back to the parent
            if (neighbor == parent) continue;

            // If the neighbor is not visited, explore it
            if (!visited[neighbor]) {
                dfs(neighbor, node, adj, visited, discTime, lowTime);

                // If there's no back edge from neighbor or its subtree,
                // the edge is critical (bridge)
                if (discTime[node] < lowTime[neighbor]) {
                    bridges.push_back({node, neighbor});
                }
            }
           lowTime[node] = min(lowTime[node], lowTime[neighbor]);
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections) {
        // Step 1: Create adjacency list
        vector<int> adj[n];
        for (auto &edge : connections) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Step 2: Initialize helper arrays
        vector<int> visited(n, 0);
        vector<int> discTime(n, 0); // Discovery time of each node
        vector<int> lowTime(n, 0);  // Lowest reachable node from this node

        // Step 3: DFS traversal (graph is connected, so start from 0)
        dfs(0, -1, adj, visited, discTime, lowTime);

        return bridges;
    }
};
