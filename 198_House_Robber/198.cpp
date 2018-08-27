
// O(1) space 
class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        //vector<int> dp(n, 0);
        //dp[0] = nums[0];
        //dp[1] = max(nums[0], nums[1]);]
        
        int last = nums[0], prev = max(nums[0], nums[1]), now = 0;
        
        for (int i = 2; i < n; ++i){
            //dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
            now = max(last+nums[i], prev);
            last = prev;
            prev = now;
        }
        
        return now;
    }
};



// Clean code 
class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < n; ++i)
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        
        return dp[n-1];
    }
};


class Solution {
public:
    int rob(vector<int>& nums) {
        
        if (nums.size() <= 0)
            return 0;
        if (nums.size() <= 2)
            return *max_element(nums.begin(), nums.end());
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = nums[1];
        
        int ans = max(dp[0], dp[1]);
        dp[1] = ans;
        
        
        for (int i = 2; i < nums.size();++i){
            dp[i]= max(dp[i-2] + nums[i], dp[i-1]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
