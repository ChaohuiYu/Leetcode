// Original thought: 4ms in 17 test cases
// TC: O(n+m) SC: O(N:)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> s;
        unordered_map<int,int> ans_m;
        vector<int> res;
        for(auto i:nums)
        {
            while (!s.empty() and i > s.top())
            {
                ans_m[s.top()] = i;
                s.pop();
            }
            
            s.push(i);    
        }
        
        for (auto i:findNums)
        {
            if (ans_m.count(i))
                res.push_back(ans_m[i]);
            else
                res.push_back(-1);
        }
        return res;
    }
};
