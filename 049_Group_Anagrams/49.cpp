class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if(strs.empty()) return res;
        unordered_map<string, vector<string>> m;
        
        for (auto i:strs)
        {
            string tmp(i);
            sort(tmp.begin(),tmp.end()); // general sort takes O(nlogn) time
            m[tmp].push_back(i);
        }
        
        for (auto i:m)
            res.push_back(i.second);
                
        return res;
    }
};