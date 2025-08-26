/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void helper(TreeNode*root, string &ans){
        if(!root){
            ans += "null,";
            return ;
        }

        ans += to_string(root->val) + ",";
        helper(root->left, ans);
        helper(root->right, ans);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        helper(root, ans);

        return ans;
    }
    TreeNode* build(queue<string> &q){
        string val = q.front();
        q.pop();

        if(val == "null")
            return NULL;
        
        TreeNode* root = new TreeNode(stoi(val));
        root->left = build(q);
        root->right = build(q);

        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string>q;

        string s = "";

        for(char c:data){
            if(c==','){
                q.push(s);
                s = "";
            }else{
                s+=c;
            }
        }
        
        return build(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));