
// Concise and pretty 

int findMin(vector<int>& nums) {
    int left = 0,  right = nums.size() - 1;
    while(left < right) {
        if(nums[left] < nums[right]) 
            return nums[left];
            
        int mid = (left + right)/2;
        if(nums[mid] > nums[right])
            left = mid + 1;
        else
            right = mid;
    }
    
    return nums[left];
}






// First thought 
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1, mid;
        if (r==0) return nums[0];
        
        
        //cout<<"values of -1:"<<nums[-1]<<endl;
        while (l<r)
        {
            mid = l+(r-l)/2;
            if (nums[mid]>nums[r]) // rotated
            {
                if (nums[mid]>nums[mid-1]) l = mid+1;
            }
        
            else // not rotated
            {
                r= mid;
            }
        
        }
        
        return nums[l];
    }
};