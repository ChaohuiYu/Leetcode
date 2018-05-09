/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// The point of this problem is the output format! ie: vector<vector<int>> 
// Use a marker to mark the end of a level!!!
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        queue<TreeNode*> treequeue;
        vector<vector<int>> v;
        vector<int> tmp;
        
        if (!root) return v;    
        else { treequeue.push(root); treequeue.push(NULL); } // marker!
    
        while (!treequeue.empty())
        {
            TreeNode* cur = treequeue.front(); treequeue.pop();
            if (cur==NULL)
            { 
                v.push_back(tmp); tmp.resize(0);
                if (treequeue.size()>0) treequeue.push(NULL);  // Put marker!
            }
            else
            {
                tmp.push_back(cur->val);
                if (cur->left)  treequeue.push(cur->left);
                if (cur->right) treequeue.push(cur->right);
            }
        }
        return v;
        
    }
};

// Recursive Way! Smart!
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        runLevel(0, root, v);
        return v;
    }
    void runLevel(int depth,TreeNode* n,  vector<vector<int>>& v)
    {
        if (n==NULL) return;
        if(v.size() == depth) v.push_back(vector<int>());  // Be Focus on this!!

        v[depth].push_back(n->val);
        if (n->left) runLevel(depth+1, n->left, v);
        if (n->right) runLevel(depth+1, n->right, v);
    }
};

