/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */




//Iterative solution
//Your runtime beats 96.62 % of cpp submissions.

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        TreeNode* tmp;
        vector<int> ans;
        stack<TreeNode*> treestack;
        
        if (root)
            treestack.push(root);
        else return ans;
        
        while (!treestack.empty())
        {
            tmp=treestack.top();
            ans.push_back(tmp->val);
            treestack.pop();
         
            
            if (tmp->right)
            {
                treestack.push(tmp->right);
            }
            
            if(tmp->left)
            {
                treestack.push(tmp->left);
            }
        }
        
        return ans;
            
        
        
    }
};



// My first thought: recursive solution 
// Your runtime beats 96.62 % of cpp submissions.
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        preorder(root,ans);
        return ans;
    }
    
    void preorder(TreeNode* root, vector<int>& v)
    {
        if (root)
        {
            v.push_back(root->val); 
            preorder(root->left,v);
            preorder(root->right,v);
            
        }
        
        else    return;

    }
};