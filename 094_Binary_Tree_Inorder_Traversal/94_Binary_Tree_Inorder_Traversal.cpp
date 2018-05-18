/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// Iterative solution TC:O(n), SC:O(n)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        stack<TreeNode*> treestack;
        TreeNode* cur= root;
        vector<int> res;
        
        while (cur or !treestack.empty())
        {
            if (cur)
            {
                treestack.push(cur);
                
                cur = cur->left;
            }
            else
            {   
                cur = treestack.top(); treestack.pop();
                res.push_back(cur->val);
                cur = cur -> right;
            }
            
        }
        
        
        return res;
    }
};




// TC:O(n), SC:O(n)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(ans, root);
        return ans;
    }
    
    void inorder (vector<int>& ans, TreeNode* root)
    {
        if (!root) return;
        else
        {
            inorder(ans,root->left);
            ans.push_back(root->val);
            inorder(ans,root->right);
        }
        
    }
};