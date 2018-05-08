/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// Iterative


// Recursive
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> res;
        postorder (res, root);
        return res;
    }
    
    void postorder(vector<int> & res, TreeNode* root){
       
        if (!root) return;  
        else
        {
            postorder(res, root->left);
            postorder(res, root->right);
            res.push_back(root->val);
            
        }
    
    }
};