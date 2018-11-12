
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
    void flatten(TreeNode* root) {
        
        if (!root)
            return;
        if (!root->left and !root->right)
            return;
        
        TreeNode* rtmp = root->right;
        // flatten left subtree
        TreeNode* leaf  = NULL;
        if (root->left){
            leaf = getLeaf(root->left);
            flatten(root->left);
            root->right = root->left;
        }
        root->left = NULL;
        
        flatten(rtmp);
        if (leaf)
            leaf->right = rtmp;
        else 
            root->right = rtmp;
    }
    
    TreeNode* getLeaf(TreeNode* n)
    {
        if (!n->left and !n->right) return n;
        else if (n->right)
            return getLeaf(n->right);
        else return getLeaf(n->left);
    }
    
};
