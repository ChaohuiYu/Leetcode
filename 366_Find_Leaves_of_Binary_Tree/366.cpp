
// Lintcode: https://lintcode.com/problem/find-leaves-of-binary-tree/description
// 650. Find Leaves of Binary Tree 

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

// Mock Interview @20180721 
class Solution {
public:
    /*
     * @param root: the root of binary tree
     * @return: collect and remove all leaves
     */
    vector<vector<int>> findLeaves(TreeNode * root) {
        // write your code here
        vector<vector<int>> res;
        find_depth(root, res);
        return res;
    }
    
    int find_depth(TreeNode* n, vector<vector<int>>& res)
    {
        if (!n) return -1;
        int depth = 1 + max(find_depth(n->left,res), find_depth(n->right,res));
        if (depth >= res.size()) res.resize(depth+1);
        res[depth].push_back(n->val);
        return depth;
        
    }
    
};
