

// We need to traverse the tree and record the diameter at the same time, 
// First I have to think about what to pass the value back to it's parent,
// clearly, it's the depth

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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        findDiameter(root, res);
        return res;
    }
    
    int findDiameter(TreeNode* n, int& res)
    {
        if (!n) return -1;
        int left = 1 + findDiameter(n->left, res);
        int right = 1 + findDiameter(n->right, res);
        
        res = max(res, left+right);
        
        return max(left, right);
        
    }
};
