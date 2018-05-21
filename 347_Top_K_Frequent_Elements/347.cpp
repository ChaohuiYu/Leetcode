class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.empty() or k==0) return {};
        vector<int> res;
        map<int,int> m;
        
        for (auto i:nums)
            ++m[i];

        // Use bucket sort
        // You Need to know the size of the bucket!
        vector<vector<int>>  bucket(nums.size() + 1); ;
        
        for (auto i:m)
            bucket[i.second].push_back(i.first);
        /*
        for (int i=bucket.size()-1;i>=0;--i)
            for (int j=0;j<bucket[i].size()-1;++j)
            {
                 res.push_back(bucket[i][j]);
                if (res.size()==k)   return res;
            }
        */
        for (int i=bucket.size()-1;i>=0;--i)
            for (auto j:bucket[i])  // THis IS the POINT!
            {
                res.push_back(j);
                if (res.size()==k)   return res;
            }
        return res;
    }
};