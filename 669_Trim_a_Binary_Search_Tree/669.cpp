
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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root) return NULL;
               
        root -> left = trimBST(root->left, L, R);
        root -> right = trimBST(root->right, L, R);
        
        if (root->val < L or root->val > R)
        {
            return root->left? root->left : root->right;
        }
        
        return root;
    }
};
