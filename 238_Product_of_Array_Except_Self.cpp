




class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       
        
        int n = nums.size();
        vector<int> product_begin(n);
        vector<int> product_end(n);
        vector<int> res(n);
        
        product_begin[0] = 1;
        product_end[0] = 1;
        
        for (int i=1;i<n;++i)
        {
            product_begin[i] = product_begin[i-1]*nums[i-1];
            product_end[i] = product_end[i-1]*nums[n-i];
        }
        
        
        for (int i=0;i<n;++i)
        {
            res[i] = product_begin[i]*product_end[n-i-1];
        }
        
        return res;
        
        
    }
        
        
};