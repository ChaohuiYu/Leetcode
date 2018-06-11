class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        vector<string> res;
        
        for (auto i:words)
            ++m[i];
        // bucket sort
        vector<vector<string>> v (words.size()+1);
        
        for(auto i:m){
            v[i.second].push_back(i.first);
            sort( v[i.second].begin(),  v[i.second].end());
        }
        
        
    
        for (auto it = v.rbegin();it!=v.rend();++it){

                for(auto j:*it)
                    if (res.size()!=k)
                        res.push_back(j);
        }
        
        return res;

    }
};