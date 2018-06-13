

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int maxLen = 0;
        unordered_map<int, int > m;  // Be aware!
    
        for(auto i:nums)
            ++m[i];
        
        for (auto it:m)
            if (m.count(it.first-1)>0) // Be aware!!!!
                maxLen = max(maxLen, it.second +m[it.first-1]);
      
        return maxLen;
    }
};


// Concise 
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int maxLen = 0;
        map<int, int > m; //!!! SLOW
    
        for(auto i:nums)
            ++m[i];
        
        for (auto it:m)
            if (m[it.first-1]>0)
                maxLen = max(maxLen, it.second+m[it.first-1]);
      
        return maxLen;
    }
};


class Solution {
public:
    int findLHS(vector<int>& nums) {
        
        int maxLen = 0;
        map<int, int > m;
        for(auto i:nums)
            ++m[i];
        int prev = 0, prev_key = 0;
        
        for (auto i:m)
        {   
            int sum = prev+i.second;
            if (prev and i.first-1==prev_key and sum>maxLen) maxLen = sum;
            prev = i.second; prev_key = i.first;
        }
       
        return maxLen;
    }
};