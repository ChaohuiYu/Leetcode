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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        TreeNode* tar = root;
        
        int max_depth = INT_MIN;
        int cur_depth = 1;
        subtreeHelper(root, cur_depth, max_depth, tar );
        return tar;
    }
    
    int subtreeHelper(TreeNode* n , int depth, int& max_level, TreeNode* &tar)
    {
        if (!n)
            return depth-1;
        int l_depth = subtreeHelper(n->left, depth+1, max_level, tar);
        int r_depth = subtreeHelper(n->right, depth+1, max_level, tar);
        
        if (depth > max_level)
        {
            tar = n;
            max_level = depth;
        }
        else if (l_depth==r_depth and l_depth==max_level)
        {
            tar = n;
        }
        
        return max(l_depth, r_depth);
        
    }
    
};

class Solution {
public:
    int utils(TreeNode *root, int curdepth, int &maxdepth, TreeNode* &curCand) {
        if(root == nullptr)
            return curdepth-1;
        
        int ldepth = utils(root->left, curdepth+1, maxdepth, curCand);
        int rdepth = utils(root->right, curdepth+1, maxdepth, curCand);

        if(curdepth > maxdepth) {
            curCand = root;
            maxdepth = curdepth;
        } else if(ldepth == rdepth && ldepth ==  maxdepth) {
            curCand = root;
        }
        
        return max(ldepth, rdepth);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        TreeNode *curCand = root;
        int maxdepth = INT_MIN;
        int curdepth = 1;
        
        utils(root, curdepth, maxdepth, curCand);
        return curCand;
    }
};
