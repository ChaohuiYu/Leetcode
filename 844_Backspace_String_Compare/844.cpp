// 


// O(2N) space 
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        
        string s1;
        string s2;
        
        for (auto i:S)
        {
            if ( i == '#'){
                if(!s1.empty()) 
                    s1.pop_back();
            }
            else    
                s1+=i;
        }
        
        for (auto i:T)
        {
            if (i=='#'){
                if(!s2.empty())
                    s2.pop_back();
            }
            else 
                s2+=i;
        }
        return s1 == s2;
    }
};

