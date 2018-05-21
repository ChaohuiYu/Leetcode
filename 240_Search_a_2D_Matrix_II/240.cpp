
//X*Y matrix dimention
//The TC:O(lgn)=O(lg(XY))
//SC:O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) return false;
    int l=0;
    int row_len = matrix.size();
    int col_len = matrix[0].size();
    int r= row_len*col_len-1;
  
    while (l<=r)
    {
      int mid = l+(r-l)/2;
      if (matrix[mid/col_len][mid%col_len]==target) return true;
      else if (matrix[mid/col_len][mid%col_len]>target) r=mid-1;
      else  l= mid+1;
    }
  
    return false;
    }
};