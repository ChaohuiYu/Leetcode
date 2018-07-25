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
