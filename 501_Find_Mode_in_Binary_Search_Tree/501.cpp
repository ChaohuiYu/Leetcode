
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */






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
