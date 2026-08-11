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
    pair<bool, int> solve(TreeNode* root){
        if(!root)
            return {true, 0};

        
        auto left = solve(root->left);
        auto right = solve(root->right);
        
        pair<bool, int> ans = {true, root->val};

        if(root->left  || root->right)
        {
            ans.first = root->val == left.second + right.second;
        }

        return ans;
    }
    bool checkTree(TreeNode* root) {
        return solve(root).first;
    }
};