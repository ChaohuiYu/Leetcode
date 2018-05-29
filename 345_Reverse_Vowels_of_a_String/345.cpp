

// Revise
class Solution {
public:
    string reverseVowels(string s) {
        
        int l = 0, r = s.length()- 1;
        int dict[256]={0};
        dict['a'] = 1, dict['A'] = 1;
        dict['e'] = 1, dict['E'] = 1;
        dict['i'] = 1, dict['I'] = 1;
        dict['o'] = 1, dict['O'] = 1;
        dict['u'] = 1, dict['U'] = 1;
        
        
        while (l<r)
        {
            if (dict[s[l]] and dict[s[r]])
            {
                swap(s[l],s[r]);
                ++l; --r;
            }
            else if (dict[s[l]])
                 --r;
            else if (dict[s[r]])
                 ++l;
            else
                {++l;--r;}   
        }
        return s;
    }
};



//My Solution
class Solution {
public:
    string reverseVowels(string s) {
        
        int l = 0, r = s.length()- 1;
        string vowels ="aeiouAEIOU";
        
        while (l<r)
        {
            if (vowels.find(s[l])!=string::npos and vowels.find(s[r])!=string::npos)
            {
                swap(s[l],s[r]);
                ++l; --r;
            }
            else if (vowels.find(s[l])!=string::npos )
                 --r;
            else if (vowels.find(s[r])!=string::npos)
                 ++l;
            else
                {++l;--r;}   
        }
        return s;
    }
};