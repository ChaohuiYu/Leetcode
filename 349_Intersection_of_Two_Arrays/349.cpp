class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> table(nums1.begin(),nums1.end());
        vector<int> res;
        for (auto num:nums2)
        {
            if (table.count(num))
            {
                table.erase(num);
                res.push_back(num);
            }
        }
        return res;
    }
};