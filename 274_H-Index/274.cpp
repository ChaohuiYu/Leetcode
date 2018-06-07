

// Hash map method O(n)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        auto n = citations.size();
        vector<int> map(n+1, 0);
        auto paper = 0;
        
        for (auto c:citations)
            if (c>=n)
                map[n]++;
            else 
                map[c]++;
        
        for (int i = n; i>=0; --i){
            paper+= map[i];
            if (paper>=i)
                return i;
        }
        return 0;
    }
};




class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        sort(citations.begin(), citations.end());  // O(nlgn)
        auto total_sum = citations.size();
        auto h_idx = 0;
        
        for (auto c:citations)
        {
            if (c>=total_sum and total_sum > h_idx)
                h_idx = total_sum;
           --total_sum;
        }      
        return h_idx;
    }
};