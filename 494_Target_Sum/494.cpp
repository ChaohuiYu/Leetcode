class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        
        int cnt = 0;
        DFS(nums,S,0,0,cnt);
        return cnt;
    }
    
    void DFS(const vector<int>& nums, int S, int sum, int pos, int & cnt )
    {
        if (pos==nums.size())
        {
            if (sum==S)
            {
                cnt++;
                return;
            }
            else
                return ;
        }
        
        
        DFS(nums,S,sum+nums[pos],pos+1,cnt);
        DFS(nums,S,sum-nums[pos],pos+1,cnt);
    }
};