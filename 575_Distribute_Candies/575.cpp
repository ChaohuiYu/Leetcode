

// One line 
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
    
       return min (candies.size()/2, unordered_set<int>(candies.begin(),candies.end()).size());
    }
};

// Original thought 
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
    
        int count = 0, num = candies.size()/2;
        unordered_set<int> s;
        
        for (auto c:candies)
        {
            if (s.count(c)<=0){
                ++count;
                s.insert(c);
            }
            
            if (count==num) return num;
        }
        return count;
    }
};