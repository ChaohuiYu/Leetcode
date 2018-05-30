

// Clean 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if (strs.empty()) return "";
        if (strs.size()==1) return strs[0];
        
        string res = strs[0];
     
        for (int i = 1;i<strs.size();++i)
        {
            int idx = 0;
            while(idx<res.size() and res[idx]==strs[i][idx]) ++idx;
            res = res.substr(0,idx);
        }
            
        return res;
    }
};


// First version
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if (strs.empty()) return "";
        if (strs.size()==1) return strs[0];
        
        string res = findCommonPart(strs[0],strs[1]);
     
        for (int i = 2;i<strs.size();++i)
            res = findCommonPart(res,strs[i]);
        return res;
        
    }
    string findCommonPart(string &s1, string &s2)
    {
        string res ="";
        
        for (int i=0; i<s1.size() and i<s2.size();++i)
            if (s1[i]==s2[i]) res+=s1[i]; 
            else break;
        return res;
    }
};