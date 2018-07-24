
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
    string tree2str(TreeNode* t) {
        
        if (!t) return "";
        string res ="";
        res += to_string(t->val);
        if (t->left) res += '(' + tree2str(t->left) + ')';
        else if (t->right) res += "()";
            
        if (t->right) res +=  '(' + tree2str(t->right) + ')';
        
        return res;
    }
   
};
