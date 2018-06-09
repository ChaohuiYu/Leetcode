class Solution {
public:
    string longestWord(vector<string>& words) {
        
        // 有想法就要去實踐它, 不要一直想著優化反而被卡死
        sort(words.begin(), words.end());  // O(nlgn)
        string res = "";
        unordered_set<string> set;
        
        for (auto i:words)
            if (i.size()< 2 or set.count(i.substr(0, i.size()-1)))
            {
                res = i.size()>res.size()? i: res;
                set.insert(i);
            }
        return  res;
    }
};