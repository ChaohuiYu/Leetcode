class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        
        if (matrix.empty() ) return {};
        int m = matrix.size();
        int n = matrix[0].size();
        vector<pair<int, int>> res;
        
        
        vector<vector<int>> p_visited(m, vector<int>(n,0));
        vector<vector<int>> a_visited(m, vector<int>(n,0));
      
        
        
        for(int i=0;i<m;++i)
        {
            DFS(matrix,p_visited, i, 0, INT_MIN);
            DFS(matrix,a_visited, i, n-1, INT_MIN);
        }
        for(int i=0;i<n;++i)
        {
            DFS(matrix,p_visited, 0, i, INT_MIN);
            DFS(matrix,a_visited, m-1, i, INT_MIN);
        }
        
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
            {
                if (p_visited[i][j] && a_visited[i][j] )
                {
                    res.push_back(pair<int, int>(i, j));
                }
            }
        return res;
        
    }
    
    void DFS(vector<vector<int>>& M, vector<vector<int>>& v, int i, int j, int prev)
    {
        if (i<0 or i>=M.size() or j<0 or j>=M[0].size() or v[i][j] or prev>M[i][j]) return ;
        v[i][j] = 1;
        
        DFS(M,v,i+1,j,M[i][j]); DFS(M,v,i-1,j,M[i][j]);
        DFS(M,v,i,j-1,M[i][j]); DFS(M,v,i,j+1,M[i][j]);
    }
};