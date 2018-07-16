class Solution {
public:
    string removeKdigits(string num, int k) {
        
        if (num.size()==k) return "0";
        int n = num.size();
        string res = "";
        
        for (int i = 0; i < n; ++i)
        {
            while ( !res.empty() and num[i] < res.back() and k > 0)
                res.pop_back(), k--;
            res += num[i];
        }
        
        while (k > 0)
            res.pop_back(),k--;
        
        while (!res.empty() and res[0] == '0')
            res.erase(0,1);
        
        
        return res.size() == 0 ? "0": res;
        
    }   
};
