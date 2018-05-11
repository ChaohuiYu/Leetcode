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
// Video: https://www.youtube.com/watch?v=xLQKdq0Ffjg
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> nodes;
        stack<TreeNode*> vistedStack;
        TreeNode* cur = root;
        TreeNode* lastNode = NULL;

        while (cur or !vistedStack.empty()) 
        {
            if (cur)
            {
                vistedStack.push(cur);
                cur = cur ->left;
            }
            else
            {
                TreeNode* topnode = vistedStack.top();

                if (topnode->right and lastNode != topnode->right)
                    cur = topnode->right;
                else
                {
                    nodes.push_back(topnode->val);  // output
                    lastNode = topnode;
                    vistedStack.pop();
                }
            }
        }
        return nodes;
    }

};




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