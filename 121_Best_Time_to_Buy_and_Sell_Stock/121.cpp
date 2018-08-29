
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int ans = 0, low = INT_MAX;
        for (auto i:prices){
            ans = max(i - low, ans);
            if (i < low) low = i;
        }
        return ans;
    }
};
