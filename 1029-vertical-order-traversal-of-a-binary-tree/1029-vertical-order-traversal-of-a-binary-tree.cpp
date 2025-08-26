class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root)
            return {};
        
        // Map to store nodes by their vertical level -> list of {row, value}
        map<int, vector<pair<int, int>>> nodes;
        // Queue for BFS {node, {vertical level, row level}}
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        q.push({root, {0, 0}});  // Start with root at vertical level 0 and row level 0
        
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            
            TreeNode* curr = node.first;
            int vertical = node.second.first;
            int row = node.second.second;
            
            // Store the node's value along with its row level
            nodes[vertical].push_back({row, curr->val});
            
            // Push left and right children into the queue with updated levels
            if (curr->left) {
                q.push({curr->left, {vertical - 1, row + 1}});
            }
            if (curr->right) {
                q.push({curr->right, {vertical + 1, row + 1}});
            }
        }
        
        vector<vector<int>> result;
        
        // Traverse the map and sort the nodes in each vertical level
        for (auto& [vertical, vec] : nodes) {
            // Sort by row level first, then by value if rows are the same
            sort(vec.begin(), vec.end(), [](pair<int, int>& a, pair<int, int>& b) {
                if (a.first == b.first) {
                    return a.second < b.second;  // Sort by value if rows are the same
                }
                return a.first < b.first;  // Sort by row level
            });
            
            vector<int> col;
            for (auto& [row, value] : vec) {
                col.push_back(value);
            }
            result.push_back(col);
        }
        
        return result;
    }
};
