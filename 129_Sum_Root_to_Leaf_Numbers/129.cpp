
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
    int sumNumbers(TreeNode* root) {
        
        if (!root) return 0;
        int res = 0;
        sumHelper(root, res, 0);
        return res;
        
    }
    
    void sumHelper(TreeNode* n, int& res, int p)
    {
        int tmp = n->val + p;
        
        if (!n->left and !n->right)
        {
            res += tmp;
            return ;
        }
        
        if (n->left)
            sumHelper(n->left, res, tmp*10);
        if (n->right)
            sumHelper(n->right, res, tmp*10);
        return;
    }
};
