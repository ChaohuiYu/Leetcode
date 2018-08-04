
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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        
        bool isbalanced = true;
        getDepth(root, isbalanced);
        return isbalanced;
        
    }
    
    int getDepth(TreeNode*n, bool& f)
    {
        if (!n)
            return -1;
        int left = 1 + getDepth(n->left, f);
        int right = 1 + getDepth(n->right, f);
        
        if (abs(left-right) > 1)
        {
            f = false;
            return 0;
        }
        return max(left, right);
    }
};
