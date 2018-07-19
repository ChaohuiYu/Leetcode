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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMBT(nums, 0, nums.size());
    }
    TreeNode* constructMBT(vector<int>& nums, int l, int r)
    {
        if (l>=r) return NULL;
        int max_idx = l;
        for (int i = l+1; i < r;++i)
            if (nums[i]>nums[max_idx]) max_idx = i;
        TreeNode* root = new TreeNode(nums[max_idx]);
        root -> left = constructMBT(nums, l, max_idx);
        root -> right = constructMBT(nums, max_idx+1, r);
        return root;
    }
    
    
    
};
