class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       
        vector<int> res(2,-1);
        if (nums.size()<=0) return res;
        

        // Find the start point 
        // If i'd like to find the "start" pointer, 
        // I MUST MOVE the right pointer first. 

        int l=0, r=nums.size()-1, mid;
        while (l+1<r)
        {
            mid = l+(r-l)/2;
            if (nums[mid]>=target) r=mid;   // Move the right pointer!
            else l=mid;
        }
        if (nums[l]==target) res[0] = l;
        else if  (nums[r]==target) res[0] = r;
        else return res;
        
       
        // Find the end point 
        l = 0, r=nums.size()-1;
        while (l+1<r)
        {
            mid = l+(r-l)/2;
            if(nums[mid]<=target) l=mid;
            else r=mid;
        }
        if (nums[r]==target) res[1] = r;
        else if  (nums[l]==target) res[1] = l;
        return res;
    
    }
};