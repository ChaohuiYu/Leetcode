// https://leetcode.com/problems/most-common-word/discuss/135468/6ms-East-to-understand-C++-solution

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
    
        unordered_map<string, int> m;
        string tmp, res;
        int count = 0;
        
        for (auto c:paragraph)
        {
            if(c>='a' and c<='z')
                tmp+=c;
            else if (c>='A' and c<='Z')
                tmp+=(c-'A'+'a');
            else if (!tmp.empty())
            {
                ++m[tmp];
                tmp.clear();
            }
        }
        // The Last word
        if (!tmp.empty())
        { 
            ++m[tmp];
            tmp.clear();
        }
        
        for (auto i:banned)
            m[i] = 0;
        
        for (auto i:m)
            if (i.second >count)
            {
                count = i.second;
                res = i.first;
            }
       return res;        
    }
};