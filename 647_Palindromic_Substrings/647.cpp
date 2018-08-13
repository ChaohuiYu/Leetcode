
// NON-DP
class Solution {
public:
    int countSubstrings(string s) {
        
        int cnt = 0;
        if (s.empty())
            return 0;
        
        for (int i = 0;i < s.length();++i)
        {
            cnt += extendString(s,i,i);
            cnt += extendString(s, i, i+1);
        }
        return cnt;
        
    }
    int extendString(string s, int left, int right){
        
        int cnt = 0;
        while (left >=0 and left < s.length() and s[left]==s[right])
        {
            left--;
            right++;
            cnt++;
        }
        return cnt;
    }
    
};
