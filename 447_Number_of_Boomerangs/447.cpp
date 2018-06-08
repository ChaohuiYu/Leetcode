class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        
        int res = 0;
        for (auto i:points)
        {
            unordered_map<int, int> m;
            for (auto j:points)
            {
                if (i==j) 
                    continue;
                else
                {
                    auto dx = i.first - j.first;
                    auto dy = i.second - j.second;
                    ++m[dx*dx + dy*dy]; 
                }
            }
            // nP2  P n 取 2 = n*(n-1)
            for (auto k:m)
            {
                if (k.second>1)
                    res += k.second*(k.second-1);
            }
        }
        return res;
    }  
};