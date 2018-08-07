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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
    
        vector<vector<int>> res;
        DFS(res, root, 0);
        reverse(res.begin(), res.end());
        return res;
        
    }
    void DFS(vector<vector<int>>& res, TreeNode* n, int level)
    {
        if (!n)
            return;
        
        if (level == res.size())
            res.push_back({});
        res[level].push_back(n->val);
        
        DFS(res, n->left, level+1);
        DFS(res, n->right, level+1);
    }
    
    
};

// Original thought
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> que;
        vector<int> tmp;
        que.push(root);
        que.push(NULL);

        
        while (!que.empty())
        {
            TreeNode* now = que.front();
            que.pop();
            if (!now)
            {
                res.push_back(tmp);
                tmp.resize(0);
                if (que.size() > 0) que.push(NULL);
                
            }
            else
            {
                tmp.push_back(now->val);
                if (now->left) que.push(now->left);
                if (now->right) que.push(now->right);
            }
        }
        reverse(res.begin(), res.end());
        return res;
        
    }
};
