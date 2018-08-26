
//TC: O(N)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
      //  dp[i] = dp[i-1] > 0 ? dp[i-1] + nums[i]:nums[i]
        vector<int> dp(nums.size());
        int ans = nums[0];
        dp[0] = nums[0];
        
        for (int i = 1; i < nums.size();++i){
             dp[i] = dp[i-1] > 0 ? dp[i-1] + nums[i]:nums[i];
             ans = max(ans, dp[i]);
        }
        return ans;
    }
};

// TC: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
      //  dp[i] = dp[i-1] > 0 ? dp[i-1] + nums[i]:nums[i]
        //vector<int> dp(nums.size());
        int ans = nums[0], sum = nums[0];
        
        for (int i = 1; i < nums.size();++i){
            // dp[i] = dp[i-1] > 0 ? dp[i-1] + nums[i]:nums[i];
             sum = sum > 0 ? sum + nums[i]:nums[i];
             ans = max(ans, sum);
        }
        return ans;
    }
}; 
