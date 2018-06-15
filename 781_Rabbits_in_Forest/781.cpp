class Solution {
public:
    int numRabbits(vector<int>& answers) {
        
        unordered_map<int,int> m;
        auto cnt = 0;
        
        for (auto i:answers)
            // if the number is repeated and the times of repeated number <= the answer 
            // then we can count them as the same color 
            m[i]++;
            
        for (auto i:m)
        {
            if (i.first>=i.second)
                cnt+=i.first+1;
            else    
             // [3:5]
             // 3333 3 => 5/4 * 4 + (5%4)?4:0 => 4+4 =8  
                cnt += i.second/(i.first+1) *(i.first+1 ) + (i.second%(i.first+1)? i.first+1:0);      
        }
        return cnt;
    }
};