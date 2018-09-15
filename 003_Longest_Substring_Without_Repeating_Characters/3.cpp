


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(128, 0);
        int max_len = 0;
        int start = 0;
        
        for(int i = 0; i < s.length(); ++i){
          
            m[s[i]]++;
            
            while(m[s[i]] > 1){
                m[s[start]]--;
                start++;
            }
            max_len = max(max_len, i-start+1);
        }
        
        return max_len;
    }
};





class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int> m(128, -1);
        int prev = 0, maxLen =0;
        //cout<<m['a']<<endl; //why
        for (auto i=0;i<s.size();++i)
        {
            if(m[s[i]]!=-1 and m[s[i]]>=prev)
            {
                prev = m[s[i]]+1;
            }
            
            maxLen = max(maxLen, i-prev+1);
            cout<<prev<<" "<<maxLen<<endl;
        
            m[s[i]] = i;
        }
        return maxLen;
    }
};
