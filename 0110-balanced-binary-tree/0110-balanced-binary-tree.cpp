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
pair<bool, int> solve(TreeNode*root){
        if(!root)
            return {true, 0};
        auto left = solve(root->left);
        auto right = solve(root->right);
        int height = max(left.second, right.second) + 1;
        return {left.first && right.first && abs(left.second - right.second) <= 1, height};
    }
    bool isBalanced(TreeNode* root) {
        auto ans = solve(root);
        return ans.first;
    }
};