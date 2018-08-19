class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        vector<int> min_cost(n, 0);
        
        min_cost[0] = cost[0];
        min_cost[1] = cost[1];
        for (int i = 2; i < n; ++i)
            min_cost[i] = min(min_cost[i-1], min_cost[i-2]) + cost[i];
        
        return min(min_cost[n-1], min_cost[n-2]);
    }
};



class Solution {
    
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> path(m+1, vector<int>(n+1, 0));
        path[1][1] = 1;
        
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j){
                
                if (i==1 and j==1)
                    continue;
                else 
                    path[i][j] = path[i-1][j] + path[i][j-1];
            }
        return path[m][n];
    }
};
