
// In the beigining, it's very straightforward to find a solution like this, 
// but the time complexity would be large.
// we can find that I recalculate the sum of each node, so actually I can save it as a parameter
 
// When we caluate the sum of the tree, we can also calcuate the result in the same time, 
// So basically we can know the answer after traversing the tree one time.


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
    int findTilt(TreeNode* root) {
        
        if (!root) return 0;
        
        int nodeTilt = 0;
        if (treeSum(root->left) >= treeSum(root->right))
            nodeTilt = treeSum(root->left) - treeSum(root->right);
        else nodeTilt =  treeSum(root->right) - treeSum(root->left);
        
        return findTilt(root->left) + findTilt(root->right) + nodeTilt;
        
    }
    int treeSum(TreeNode* n)
    {
        if (!n) return 0;
        
        int sum = 0 ;
        sum += n->val + treeSum(n->left) + treeSum(n->right);
        return sum;
    }
    
};



// Clean Code 
class Solution {
public:
    int findTilt(TreeNode* root) {
        
        if (!root) return 0;
        int res = 0;
        postOrder(root, res);
        return res;
    }
    
    int postOrder(TreeNode* n, int& res)
    {
        if (!n) return 0;
        int leftSum = postOrder(n->left, res);
        int rightSum = postOrder(n->right, res);
        
        res += abs(leftSum-rightSum);
        return leftSum + rightSum + n->val;
    }
};
