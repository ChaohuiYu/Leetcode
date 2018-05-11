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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)  return false;
        if (!root->left and !root->right and root->val==sum ) return true;
        return hasPathSum(root->left,sum-root->val) or hasPathSum(root->right, sum-root->val);
    }
};