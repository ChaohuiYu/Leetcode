class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> combinations(amount+1, 0);
        
        combinations[0] = 1;
        for (auto c:coins)
            for (int i = 1; i <= amount; ++i){
                
                if (i-c >=0)
                    combinations[i] += combinations[i-c];
            }
        return combinations[amount];
        
    }
};
