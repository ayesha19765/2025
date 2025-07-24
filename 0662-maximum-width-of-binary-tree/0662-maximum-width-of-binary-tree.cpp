/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        long long maxWidth = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});  // node, index

        while (!q.empty()) {
            int size = q.size();
            long long minIdx = q.front().second;
            long long first = 0, last = 0;

            for (int i = 0; i < size; ++i) {
                auto [node, idx] = q.front(); q.pop();
                idx -= minIdx;  // normalize to prevent overflow

                if (i == 0) first = idx;
                if (i == size - 1) last = idx;

                if (node->left) q.push({node->left, 2 * idx + 1});
                if (node->right) q.push({node->right, 2 * idx + 2});
            }

            maxWidth = max(maxWidth, last - first + 1);
        }

        return (int)maxWidth;
    }

};