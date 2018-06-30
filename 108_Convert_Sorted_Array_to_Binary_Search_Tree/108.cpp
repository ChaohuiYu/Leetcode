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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        if (nums.size()==0) return NULL;
        if (nums.size()==1) return new TreeNode(nums[0]);
        return DFS(nums,0,nums.size()-1);

    }
    
    TreeNode* DFS(vector<int>& nums, int l, int r)
    {
        if (l>r) return NULL;
        int mid = (l+r)/2;
        TreeNode* root= new TreeNode(nums[mid]);
        root->left = DFS(nums,l, mid-1);
        root->right = DFS(nums,mid+1,r);
        return root;
    }
};