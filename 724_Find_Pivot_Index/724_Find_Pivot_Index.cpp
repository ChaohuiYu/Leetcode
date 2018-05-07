
//First thought
//Your runtime beats 45.77 % of cpp submissions.
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int total_sum = 0;
        int tmp_sum = 0;
            
        for (int i:nums) total_sum+=i;
        
        for(int j=0; j<nums.size();++j) 
        {    
           
           if (tmp_sum*2==(total_sum-nums[j]))
           {
               return j;
           }
           tmp_sum+=nums[j];
        }
        return -1;
    }
};
