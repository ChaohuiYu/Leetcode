class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> plate(26,0);
        int mini_len = 15; // Initial
        string ans;
        
        for (auto i:licensePlate)
            if ((i>='a' and i<='z') or (i>='A' and i<='Z'))
                ++plate[tolower(i)-'a'];
        
        for(auto i:words)
        {
            vector<int> m_words(26,0);
            for (auto j:i) // O(15)
                ++m_words[j-'a'];
            
            // Compare two maps O(26)
            int k = 0;
            for(;k < 26; ++k) 
                if(m_words[k]-plate[k]<0)
                    break;   
            if (k==26 and i.size()<mini_len ) { mini_len = i.size(); ans = i;}
        }
        return ans;
    }
};