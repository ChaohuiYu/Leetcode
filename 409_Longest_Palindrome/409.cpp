class Solution {
public:
    int longestPalindrome(string s) {
        auto count = 0;
        bool single = false;
        int map[256] = {0};
        for (auto c:s)
            ++map[c];
        
        for(int i =0;i<256;++i)
        {
            if (map[i]%2==0)
                count+=map[i];
            else 
            {
                if (map[i]>2) count+=map[i]-1;
                single = true;
            }   
        }
        return single? count+1:count;
    }
};