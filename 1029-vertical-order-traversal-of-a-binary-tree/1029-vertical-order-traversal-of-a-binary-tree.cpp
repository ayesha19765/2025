class Solution {
public:
    map<int, vector<pair<int,int>>> nodes;

    void dfs(TreeNode* root, int row, int col) {
        if (!root) return;
        nodes[col].push_back({row, root->val});

        dfs(root->left, row + 1, col - 1);
        dfs(root->right, row + 1, col + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);

        vector<vector<int>> result;
        for (auto& [col, vec] : nodes) {
            sort(vec.begin(), vec.end()); // Only sorts by row since values are already ordered in BST
            vector<int> colVals;
            for (auto& [row, val] : vec) {
                colVals.push_back(val);
            }
            result.push_back(colVals);
        }
        return result;
    }
};
