

// Sort soultion 
class Solution {
public:
    string frequencySort(string s) {
        int counts[256] = {0};
        for (char ch : s)
            ++counts[ch];
        sort(s.begin(), s.end(), [&](char a, char b) { 
            return counts[a] > counts[b] || (counts[a] == counts[b] && a < b); 
        });
        return s;
    }
};



// An improvement but takes O(nlgn)
string frequencySort(string s) {
    unordered_map<char, int> freqOfChar;
    for(char c : s) {
        freqOfChar[c] ++;
    }
    
    map<int, string> dupStr;
    for(auto v : freqOfChar) {
        char c = v.first;
        int n = v.second;
        dupStr[n] += string(n, c);
    }
    
    string res;
    for(auto rit = dupStr.rbegin(); rit != dupStr.rend(); ++rit) {
        res += rit->second;
    }
    return res;
}


// U need to think about what if the string is BIG, 
// then the space use would be awful.
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        string res;
        vector<string> v(s.size()+1, "");
        for (auto c:s)
            ++m[c];
        
        for (auto i:m)
            v[i.second]+=i.first;
        
        for(auto i= v.size()-1; i>0;--i)
        {
            if (v[i]!="")
                for (auto j:v[i]) 
                    for (int k=0;k<i;++k)// repeat 
                        res+=j;
        }
       
        
        return res;
    }
};