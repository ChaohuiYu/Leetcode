class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        if (nums.size()<2) return 0;
        
        unordered_map<int,int> m;
        auto preSum = 0, maxLen = 0;
        
        m[0] = -1;

        for (auto i=0;i<nums.size();++i)
        {
            if(!nums[i]) preSum+=-1;
            else preSum+=1;
            
            if (m.count(preSum))
                maxLen = max(maxLen, i-m[preSum]);
            else
                m[preSum] = i;
        }
        
        return maxLen;
    }
};