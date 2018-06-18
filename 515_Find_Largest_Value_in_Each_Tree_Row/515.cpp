/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Recursive 15ms in 78 test cases
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
     
        vector<int> res;
        preorder(root, 0, res);
        return res;
    }
    
    void preorder(TreeNode* node, int height, vector<int>& res )
    {
        if (!node) return;
        if(height>=res.size())
            res.push_back(node->val);
        else
        {
            res[height] = max(res[height], node->val);
            
        }
        preorder(node->left,height+1,res);
        preorder(node->right,height+1,res);
    }
};


 // 15ms in 78 test cases
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        // Use BFS
        queue<TreeNode*> q;q.push(root);
        int max_val = INT_MIN;
        vector<int> res;
        q.push(NULL); // mark as end of level
        
        while (!q.empty())
        {
            TreeNode* node = q.front(); q.pop();
            
            if (node)
            {
                max_val = max(max_val, node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            else if (node==NULL) 
            {
                res.push_back(max_val);
                max_val = INT_MIN; // RESET
                if (!q.empty()) q.push(NULL);
            }    
        }
        return res;
    }
};