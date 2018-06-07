

// Use two maps to record the position idx
// Use istringstream to segment the string 
// Consider two corner cases:
// 1. str is longer than pattern 
// 2. pattern is longer than str

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        // Use two maps
        unordered_map<char, int> p_m;
        unordered_map<string, int> s_m;
        
        istringstream is(str);
        int i = 0;
        auto size = pattern.size();
        for (string word; is>>word;++i)
        {
            if(i==size or p_m[pattern[i]]!=s_m[word])
                return false;
            p_m[pattern[i]] = s_m[word] = i+1;
        }
        
        if (i==size) return true;
        return false;
            
    }
};