
/*
We can find that the number of nodes is the condition to help us to find the 
target either in the left or right substree.

So, we can know that there are three cases: to find in left-subtree, right-subtree and 
the current node is the target.

*/

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
    int kthSmallest(TreeNode* root, int k) {
        
        int cnt = countNode(root->left);
        if (k <= cnt)
        {
            return kthSmallest(root->left, k);
        }
        else if (k > cnt+1)
        {
            return kthSmallest(root->right, k-1-cnt);
        }
        
        return root->val;
        
    }

    int countNode(TreeNode* n)
    {
        if (!n) return 0;
        return 1 + countNode(n->left) + countNode(n->right);
    }
};
