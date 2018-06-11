class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        
        // Need to check three things 
        bool row[9][9] = {0}, col[9][9] = {0}, grid[9][9] ={0};
        
        for (auto i=0;i<board.size();++i)
            for (auto j=0;j<board[i].size();++j)
            {
    
                if (board[i][j]!='.')
                {
                    int x = board[i][j]-'0'-1; // Be aware here!
                    
                    if (row[i][x] or col[j][x] or grid[(i/3)*3+(j/3)][x])
                        return false;
                    row[i][x]=col[j][x]=grid[(i/3)*3+(j/3)][x]= 1;   
                }
                
            }
        return true;

    }
};