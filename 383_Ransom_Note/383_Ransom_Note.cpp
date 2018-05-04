

//Your runtime beats 37.27 % of cpp submissions.
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        unordered_map<char, int> map;
        for (char c:magazine)   ++map[c];
        for (char c:ransomNote)
        {
            if (--map[c]<0) return false;
        }
        return true;
        
    }
};


// Using vector
// Your runtime beats 97.08 % of cpp submissions.
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        vector<int> map(26);
        for (char c:magazine)   ++map[c-'a'];
        for (char c:ransomNote)
        {
            if (--map[c-'a']<0) return false;
        }
        return true;
        
    }
};