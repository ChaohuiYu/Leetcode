
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
    vector<double> averageOfLevels(TreeNode* root) {
        
        if (!root) return {};
        queue<TreeNode*> q;
        vector<double> res;
        double sum = 0;
        int count = 0;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty())
        {
            TreeNode* now = q.front();
            q.pop();
            
            if (!now)
            {
                double avg = sum /count;
                res.push_back(avg);
                sum = 0, count =0;
                if (!q.empty()) q.push(NULL);
                
            }      
            else
            {
                sum += now->val;
                ++count;
                if (now->left) q.push(now->left);
                if (now->right) q.push(now->right);
            }
        
        }
        return res;
        
        
    }
};
