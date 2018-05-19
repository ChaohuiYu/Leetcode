class Solution {
public:
    int firstUniqChar(string s) {
        if (s.empty()) return -1;
        int char_map[128]={0};
        for (int i=0;i<s.length();++i)
            ++char_map[s[i]];
        for (int i=0;i<s.length();++i)
            if (char_map[s[i]]==1) return i;
        return -1;
    }
};