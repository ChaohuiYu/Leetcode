

// First thought 
// TC: O(n)
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        
        int max=0;
        int max_idx = 0;
        int second=0;
        
        for (int i=0;i<nums.size();++i)
        {
            if (nums[i] >= max) { second =max; max = nums[i]; max_idx = i; }
            else if (nums[i]>=second) second = nums[i];
        
        }
        
        if (max >= second*2)  return max_idx;
        else return -1;
            
               
    }
};