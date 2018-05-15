class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int l=0, r=nums.size()-1, len_idx=nums.size()-1, mid;
        if (r==0) return 0;
        
        while (l<r)
        {
            mid = l+(r-l)/2;
            if (mid+1<=len_idx and nums[mid+1]>nums[mid]) l = mid+1; 
            else  r = mid;
        }  
        return l;
        
    }
};