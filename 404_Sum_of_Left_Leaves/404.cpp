
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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        return  leftSum(root->left, true) + leftSum(root->right, false);
    }
    
    int leftSum(TreeNode* n, bool from_left)
    {
        if (!n) return 0;
        if (!n->left and !n->right and from_left) return n->val;
        return leftSum(n->left, true) + leftSum(n->right, false);
        
    }
};
