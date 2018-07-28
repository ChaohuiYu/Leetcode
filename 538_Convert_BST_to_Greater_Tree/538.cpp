
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
    TreeNode* convertBST(TreeNode* root) {
        
        int sum = 0;
        DFS(root, sum);
        return root;
    }
    void DFS(TreeNode* n, int& sum)
    {
        if (!n)
            return;
        DFS(n->right, sum);
        //Do something
        sum+=n->val; n->val = sum;
        DFS(n->left, sum);
    }
};
