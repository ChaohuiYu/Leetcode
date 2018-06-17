
// TC:O(H*W)
// SC:O(W)
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
      
      if(wall.empty()) return 0;
      
      unordered_map<int, int> m;
      int max_gap = 0;
      int height = wall.size();
      
      // buid up the map
      for (auto i:wall)
      {
        int gap = 0;
        for(auto j=0;j<i.size()-1;++j)
        {
          gap+=i[j];
          max_gap = max(max_gap, ++m[gap]);
            
        }
      
      }
      return height-max_gap;      
    }
};