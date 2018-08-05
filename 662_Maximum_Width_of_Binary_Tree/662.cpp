
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
    int widthOfBinaryTree(TreeNode* root) {
        
        int num = 1, w = 0;
        vector<int> lefts;
        DFS(root, lefts, num, 1, w);
        return w;
    
    }
    
    void DFS(TreeNode* n, vector<int>& lefts, int num, int level, int& w)
    {
        if (level > lefts.size())
        {
            lefts.push_back(num);
        }
        
        w = max (w, num-lefts[level-1]+1);
        if (n->left)
            DFS(n->left, lefts, num*2, level+1, w);
        if (n->right)
            DFS(n->right, lefts, num*2+1, level+1, w);
        
    }
};
