class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        if (nums.size()<3) return {};
        
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i=0; i<=nums.size()-3;++i)
        {
            if (i==0 or nums[i]!=nums[i-1])
            {
                int left = i+1;
                int right = nums.size()-1;
                
                while (left<right)
                {
                    int sum = nums[i]+nums[left]+nums[right];
                    if (sum==0) 
                        res.push_back({nums[i], nums[left], nums[right]});
                    if (sum<0)
                    {
                        int curstate = left;
                        while(left<right and nums[curstate] == nums[left])
                            ++left;
                    }
                    else
                    {
                        int curstate = right;
                        while(left<right and nums[curstate] == nums[right])
                            --right;
                    }
                }
            }
        }
        
        return res;
    }
};