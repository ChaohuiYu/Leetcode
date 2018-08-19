class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));

        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j){
                
                if (obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                
                if (i==0 or j==0){
                    
                    if (i==0 and j==0) dp[i][j] = 1;
                    else if (i==0) dp[i][j] = dp[i][j-1];
                    else if (j==0) dp[i][j] = dp[i-1][j];
                    continue;
                }
            
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        return dp[m-1][n-1];
    }
};
