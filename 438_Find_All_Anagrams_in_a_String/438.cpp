
// Sliding window

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> s_v (26,0), p_v(26,0), res;
        auto s_size = s.size(), p_size = p.size();
        if (s_size < p_size) return {};
        
        for (auto i = 0; i < p_size; ++i)
        {
            ++s_v[s[i]-'a'];
            ++p_v[p[i]-'a'];
        }
        
        if (s_v==p_v) res.push_back(0);
        
        for (auto i = p_size; i < s_size; ++i)
        {
            ++s_v[s[i]-'a'];
            --s_v[s[i-p_size]-'a'];
            if (s_v==p_v) 
                res.push_back(i-p_size+1);
        }
        return res;
    }
};


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
     
        // O(n*nlgn) = >TLE
        auto s_size = s.size();
        auto p_size = p.size();
        int m[26] ={0};
        vector<int> res;
        
        if (s_size<p_size) return {};
        
        for (auto c:p)
            ++m[c-'a'];
     
        for (auto i = 0; i<=s_size-p_size;++i)
        {
            string tmp = s.substr(i, p_size);
            // Stcuk at how to compare the Anagrams   
            int t_m[26] ={0}; 
            for (auto t:tmp)
                ++t_m[t-'a'];
            
            int j =0;
            for (;j<26;++j)
                if (m[j]!=t_m[j])
                    break;
    
            if (j==26) res.push_back(i);
        }
        return res;
    }
};