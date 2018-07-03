class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        DFS(image, sr, sc, newColor,image[sr][sc]);
        return image;
    }
    
    void DFS(vector<vector<int>>& image, int i, int j, int color, int s_pixel)
    {
        if (i<0 or i>=image.size() or j<0 or j>=image[0].size() or image[i][j]!=s_pixel or image[i][j]==color)
            return ;
        
        image[i][j] = color;
        DFS(image,i+1,j,color,s_pixel); DFS(image,i-1,j,color,s_pixel);
        DFS(image,i,j+1,color,s_pixel); DFS(image,i,j-1,color,s_pixel);
    }
};