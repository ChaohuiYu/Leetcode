class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        stack<int> s;
        int n = nums.size();
        vector<int> res(n, -1);
        
        for ( int i = 0; i < 2 * n; ++i)
        {
            int j = i % n;
            while(!s.empty() && nums[j] >nums[s.top()])
            {
                res[s.top()] = nums[j];
                s.pop();
            }
            
           if (i<n) s.push(i);
        }
        return res;
    
    }
};
