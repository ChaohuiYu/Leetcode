

// PreSum
// why sum-k?
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        auto sum = 0, cnt = 0;
        unordered_map<int, int> sumMap;
        sumMap[0] = 1;
        
        for (auto i:nums)
        {
            sum+=i;
            cnt+=sumMap[sum-k];
            ++sumMap[sum];
        }
        return cnt;
    }
};



// brute-force 469ms in 80 test cases 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        auto cnt = 0;
        for (auto i=0;i<nums.size();++i){
            
            int sum = nums[i];
            if (sum ==k) 
                ++cnt;
            
            for (auto j = i+1; j < nums.size();++j)
            {
                sum+=nums[j];
                if (sum==k)
                    cnt++;
            }
        }
        return cnt;
    }
};