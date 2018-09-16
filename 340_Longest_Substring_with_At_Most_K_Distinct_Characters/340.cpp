
class Solution {
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        // write your code here
        unordered_map<char, int> m;
        int start = 0, max_len = 0;
        
        for (int i = 0; i < s.length(); ++i){
            m[s[i]]++;
            
            while(m.size() > k){
                if(--m[s[start]] == 0) m.erase(s[start]);
                start++;
            }
            max_len = max(max_len, i - start +1);
        }
        return max_len;
    }
};
