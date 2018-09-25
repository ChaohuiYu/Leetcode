

class Solution {
public:
    /**
     * @param nums:  an array of n integers
     * @param target: a target
     * @return: the number of index triplets satisfy the condition nums[i] + nums[j] + nums[k] < target
     */
    int threeSumSmaller(vector<int> &nums, int target) {
        // Write your code here
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int result = 0;
        
        for (int i = 0; i < nums.size()-2; ++i){
                int l = i+1, r = nums.size()-1;
                while(l < r){
                    int sum = nums[i] + nums[l] + nums[r];
                    if (sum < target){
                        result += (r-l);
                        ++l;
                    }else
                        --r;
                
                    
                }
        }
        return result;
    }
};
