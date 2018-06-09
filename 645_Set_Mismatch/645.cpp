//645. Set Mismatch

//  SC can be optimized to O(1)
//  Use flag, ie, the minus  


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
     
        // find the duplicate 
        // find the lost num
        // TC: O(2N)
        auto n = nums.size();
        vector<int> res;
        int m[n+1] = {0};
        
        for (auto i:nums)
        {
            if (m[i]!=0) res.push_back(i); 
            ++m[i];
        }
        
        for(auto i = 1; i < n+1; ++i)
            if (m[i]==0)
                res.push_back(i);
        return res;
    }
};