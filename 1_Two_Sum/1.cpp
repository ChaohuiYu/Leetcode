class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> m;
        if (nums.size()<1) return res;
        for (int i=0;i<nums.size();++i)
        {
            int value;
            value = target-nums[i];
            if (m.count(nums[i])) {res.push_back(m[nums[i]]);res.push_back(i);}
            m.insert(make_pair(value, i));
        
        }
        
        return res;
        
    }
};