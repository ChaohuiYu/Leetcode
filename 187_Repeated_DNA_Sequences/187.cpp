class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        if (s.size()<=10) return {};
        vector<string> res;
        unordered_map<string, int> m;
        
        for (auto i = 0 ; i <= s.size()-10; ++i)
            m[ s.substr(i, 10)]++;
        
        for (auto i :m)
            if (i.second>=2)
                res.push_back(i.first);
        return res;
    }
};