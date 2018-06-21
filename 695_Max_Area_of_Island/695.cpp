class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
     
        int maxArea = 0;
        
        for (auto i=0;i<grid.size();++i)
            for(auto j=0;j<grid[0].size();++j)
            {
               if(grid[i][j])
                   maxArea = max(maxArea,traverse(grid, i, j));
            }
        return maxArea;
    }
    
    
    int traverse(vector<vector<int>>& G, int i, int j)
    {
        if (i>=0 && i<G.size() && j>=0 && j<G[0].size() && G[i][j])
        {   G[i][j] = 0 ;
            return 1+traverse(G,i+1,j)+traverse(G,i-1,j)+traverse(G,i,j+1)+traverse(G,i,j-1);
        }
        else
            return 0;
    
    }
};