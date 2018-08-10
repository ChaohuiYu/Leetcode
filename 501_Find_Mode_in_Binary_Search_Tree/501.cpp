
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
    int cnt = 0;
    int max_cnt = 0;
public:
    vector<int> findMode(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        int curval = INT_MIN;
        inOrder(root, res, curval);
        return res;
    }
    void inOrder(TreeNode*n, vector<int>& res, int& curval)
    {
        if (!n) return;
        
        inOrder(n->left, res, curval);
        
        if (curval==n->val)
            cnt++;
        else{
            cnt = 1;
            curval = n->val;
        }
        if (cnt > max_cnt){
            max_cnt = cnt;
            res.clear();
            res.push_back(n->val);
        }
        else if (cnt == max_cnt)
            res.push_back(n->val);
 
        inOrder(n->right, res, curval);
    }
};


// Trivial
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        if (!root) return {};
        unordered_map< int, int> m;
        vector<int> res;
        int max = 0;
        DFS(m, root, max);
        
        for (auto i:m)
            if (i.second==max)
                res.push_back(i.first);
        return res;
    }
    
    void DFS(unordered_map< int, int>&m, TreeNode* n, int& max)
    {
        if (!n)
            return;
        if (++m[n->val] > max)
            max = m[n->val];
        DFS(m, n->left, max);
        DFS(m, n->right, max);
    }
};
