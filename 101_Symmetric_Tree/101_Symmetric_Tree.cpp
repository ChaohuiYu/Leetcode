
// Iterative Solution

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        
        if (!root) return true;
        queue<TreeNode*> treequeue;
        
        treequeue.push(root->left);
        treequeue.push(root->right);
        
        while (!treequeue.empty())
        {
            TreeNode* node1 = treequeue.front(); treequeue.pop();
            TreeNode* node2 = treequeue.front(); treequeue.pop();
            
            // 注意順序!!!!!
            // (!node1 or !node2) 不能放前面！！！
            if (!node1 and !node2) 
                continue;
            else if (!node1 or !node2)
                return false;
            
            else 
            {
                if (node1->val!=node2->val)
                    return false;
                else
                {
                    treequeue.push(node1->left);
                    treequeue.push(node2->right);
                    treequeue.push(node1->right);
                    treequeue.push(node2->left);
                }
            }
            
        }
        return true;
        
    }
};

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
    bool isSymmetric(TreeNode* root) {
        
        if (root==NULL)
             return true;
        
        return helper(root->left, root->right);
        
    }
    
    bool helper (TreeNode* l, TreeNode* r)
    {
        if (l and r)
        {
            if (l->val==r->val)
                return helper(l->left, r->right) && helper(l->right, r->left);
            else
                return false;
        }
        else if (!l and !r)
        {
            return true;
        }
        else 
            return false;
        
    }
};