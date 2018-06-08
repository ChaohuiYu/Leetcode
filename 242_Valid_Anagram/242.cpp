

// TC:O(256+N) SC:O(256) 
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if (s.length()!=t.length()) return false; // Smart!
        int m[256] = {0};
        for (int i =0; i<s.length();++i)
        {
            ++m[s[i]];
            --m[t[i]];
        }
        for (auto i:m)
            if(i) return false;
        return true;
    }
};



// TC: O(2N+256) SC: O(256*2)
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> s_map(256,0), t_map(256,0);
        for (auto i:s)
            ++s_map[i];
        for (auto i:t)
            ++t_map[i];
        return s_map==t_map;
    }
};