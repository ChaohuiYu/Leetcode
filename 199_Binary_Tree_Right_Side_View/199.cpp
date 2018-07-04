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
    vector<int> rightSideView(TreeNode* root) {
        
        if (!root) return {};
        queue<TreeNode*> q;
        vector<int> res;
        q.push(root);q.push(NULL);
        TreeNode* prev;
        
        while (!q.empty()){
            TreeNode* n = q.front();
            q.pop();
            if (n==NULL)
            {
                res.push_back(prev->val);
                if (!q.empty()) q.push(NULL);
            }
            else
            {
                if (n->left)   q.push(n->left);
                if (n->right)  q.push(n->right);
                prev = n;
            }
        }
        return res;
        
    }
};