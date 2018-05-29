
//My posts: https://leetcode.com/problems/count-and-say/discuss/134563/C++-clean-and-easy-solution

class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        if (n<=0) return res;
     
        for (int i=1;i<n;++i)
        {
            // Initial value
            int count = 0;
            char prev = '0';
            string tmp = "";
            
            for (auto c:res)
            {
            
                if(prev=='0' or c==prev) 
                    ++count;
                else 
                {   // Output & Reset
                    tmp+=count+'0';tmp+=prev; 
                    count = 1;
                }
                prev = c;
            }
            
            tmp+=(count+'0');tmp+=prev;
            res = tmp;
        }
        return res;
    }
};