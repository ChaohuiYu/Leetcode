/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Obviously, BFS->use recursuve 
// Come up with the stop condition
// Be aware the way which you try to track the bool-type data "&&"



class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
    
        if (p==NULL and q==NULL)
            return true;
        
        if ((!p and q) or (p and !q)) //at least one node is NULL
            return false; 
        
        return (p->val==q->val) && (isSameTree(p->left, q->left)) && (isSameTree(p->right,q->right));
      
    }
};
