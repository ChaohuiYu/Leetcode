
 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Clean code:

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 and !t2) return NULL;
        else if (t1 and t2)
        {
            TreeNode* n = new  TreeNode(t1->val+t2->val);
            n ->left = mergeTrees(t1->left, t2->left);
            n->right = mergeTrees(t1->right, t2->right);
            return n;
        }
        
        else
            return t1? t1:t2;
    }
};

// First thought  Not concise
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
         TreeNode* n;
        if (!t1 and !t2) return NULL;
        else if (t1 and !t2)
        {
             n = new  TreeNode(t1->val);
             n->left = t1->left;
             n->right =  t1->right;
            
        }

        else if (!t1 and t2)
        {
             n = new  TreeNode(t2->val);
             n->left = t2->left;
             n->right =  t2->right;            
        }
   
        else if (t1 and t2)
        {
            n = new  TreeNode(t1->val+t2->val);
            n ->left = mergeTrees(t1->left, t2->left);
            n->right = mergeTrees(t1->right, t2->right);
        }
        return n;
    }
};
