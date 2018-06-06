
// Concise code 
// 61 / 61 test cases passed. 18 ms
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        unordered_map<int, int> map;
        vector<int> res;
        int max_count = 0;
        // Build the map 
        sum_subTree(root, map, max_count);
        
        // Iterate the map 
        for (auto i:map)
            if (i.second==max_count)
                res.push_back(i.first);       
        return res;
    }
    
    int sum_subTree(TreeNode* n, unordered_map<int, int> &m, int &count)
    {
        if (!n) return 0;
        int sum = sum_subTree(n->left,m,count)+ sum_subTree(n->right,m,count) + n->val;
        if(++m[sum] > count) count = m[sum];
        return sum;
    }
};






// 61 / 61 test cases passed. 15ms
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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        if (!root) return {};
        unordered_map<int, int> map;
        vector<int> res;
        // build the map 
        sum_subTree(root, map);
        
        int max_times = 0;
        // iterate the map
        for (auto i:map)
            if (i.second>max_times) 
                max_times=i.second;
        for (auto i:map)
            if (i.second==max_times)
                res.push_back(i.first);
                
        return res;
    }
    
    int sum_subTree(TreeNode* n, unordered_map<int, int> &map)
    {
        
        if (!n->left and !n->right)
        {   
            ++map[n->val];
            return n->val;
        }
        else if (n->left and n->right)
        {
            int sum = n->val+sum_subTree(n->left, map)+sum_subTree(n->right, map);
            ++map[sum];
            return sum;
        }
    
        else if (n->left)
        {
            int sum = n->val+sum_subTree(n->left, map);
            ++map[sum];
            return sum;
        }
        else if (n->right)
        {
             int sum = n->val+sum_subTree(n->right, map);
             ++map[sum];
            return sum;
        }
        
    }
};