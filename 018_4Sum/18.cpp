class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        if (nums.size()<4) return {};
        vector<vector<int>> res;
        sort (nums.begin(), nums.end());
        
        for (int i=0;i<nums.size()-3; ++i)
        {
            if (i==0 or nums[i]!=nums[i-1])
            {
                
                for (int j=i+1;j<nums.size()-2;++j)
                {
                    if (j==i+1 or nums[j]!=nums[j-1])
                    {
                        int lo = j+1;
                        int hi = nums.size()-1;
                        
                        while (lo<hi)
                        {
                            int sum = nums[i]+nums[j]+nums[lo]+nums[hi];
                            if (sum==target)
                            {
                                res.push_back({ nums[i], nums[j], nums[lo], nums[hi]});
                                while(lo<hi and nums[lo]==nums[lo+1]) lo++;
                                while(lo<hi and nums[hi]==nums[hi-1]) hi--;
                                lo++;hi--;
                            }
                            else if (sum<target) lo++;
                            else hi--;
                        }
                    }
                }
                
            }
        }
        return res;
        
    }
};