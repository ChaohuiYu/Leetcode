
// First thought!
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// Clean code!
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> set;
        return traverse(root, set, k);
    
    }
    
    bool traverse(TreeNode* n, unordered_set<int>& s, int k)
    {
        if (!n) return false;
        if (s.count(n->val))
            return true;
        s.insert(k-n->val);
        return traverse (n->left, s, k) or traverse (n->right, s, k);
    }
};
 

// First thought 
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        bool find = false;
        unordered_map<int, int> m;
        traverse(root, m, k, find);
        return find;
    }
    
    void traverse(TreeNode* n, unordered_map<int, int>& m, int k, bool & find )
    {
        if (!n) return;
        else
        {
            if (m[n->val]>0)
            {
                find = true;
                return;
            }
            m[k-n->val]++;
            traverse (n->left, m, k, find);
            traverse (n->right, m, k, find);
        }
    }
};
