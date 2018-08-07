
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
         
        vector<TreeNode*> res;
        unordered_map<string, int> m;
        dfs(res, m, root);
        return res;
    }
    string dfs(vector<TreeNode*>& res, unordered_map<string, int>& m, TreeNode* n){
        if (!n)
            return "";
        string str = to_string(n->val) + ',' + dfs(res, m, n->left) + ',' + dfs(res, m, n->right);
        if (m[str]++ == 1) res.push_back(n);
        return str;
    }
};
