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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        
        if (!s and !t)
            return true;
        if (!s or !t)
            return false;
        if (isSametree(s,t))
            return true;
        else
            return isSubtree(s->left, t) or isSubtree(s->right, t);
    }
    bool isSametree(TreeNode* s, TreeNode*t)
    {
        if (!s and !t)
            return true;
        if (!s or !t)
            return false;
        if (s->val != t->val)
            return false;
        return isSametree(s->left, t->left) and isSametree(s->right, t->right);
    }
};
