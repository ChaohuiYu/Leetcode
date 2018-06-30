
// Without extra space 
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        
        int circle = 0;
        for(int i=0;i<M.size();++i)
        {
            if(M[i][i]==1)
            {
                M[i][i] = 0;
                DFS(M,i);
                circle++;
            }
                
        }
        return circle;
        
    }
    void DFS(vector<vector<int>>& M, int i)
    {
        for(int j=0;j<M.size();++j)
        {
            if(M[i][j]==1 and M[j][j]==1)
            {
                M[j][j] = 0;
                DFS(M,j);
            }
        }
    }
    
};



class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        
        int circle = 0;
        vector<bool> checked (M.size(),0);
        for(int i=0;i<M.size();++i)
        {
            if(!checked[i])
            {
                DFS(M,checked,i);
                circle++;
                
            }
        }
        return circle;
        
    }
    void DFS(vector<vector<int>>& M, vector<bool>& checked, int i)
    {
        for(int j=0;j<M.size();++j)
        {
            if(M[i][j]==1 and checked[j]==0)
            {
                checked[j]=1;
                DFS(M,checked,j);
            }
        }
    }
    
};