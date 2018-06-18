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
    int findBottomLeftValue(TreeNode* root) {

        int val = 0, max_row = 0;
        preorder(root, 1, max_row, val);
        return val;
    }
    
    void preorder(TreeNode* node, int row, int& max_row, int& val)
    {
        if (!node) return ;
        if (row>max_row && !node->left && !node->right )
        {
            max_row = row;
            val = node->val;
        }
        preorder(node->left,row+1, max_row, val);
        preorder(node->right,row+1, max_row, val);
        
    }
};