/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        vector<string> res;
        DFS(root, res, "");
        return res;
    }
    void DFS(TreeNode* n, vector<string> &res, string tmp)
    {
        tmp+=to_string(n->val);
        if (!n->left && !n->right)
        {
            res.push_back(tmp);
            return ;
        }
        if(n->left) DFS(n->left,res,tmp+"->");
        if(n->right) DFS(n->right,res,tmp+"->");
    }
};