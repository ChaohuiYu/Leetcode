class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack<int> s;
        int size = temperatures.size();
        vector<int> res(size,0);
        
        for (auto i=0; i<size;++i){
            
            while (!s.empty() and temperatures[i]>temperatures[s.top()])
            {
                auto top = s.top();
                res[top] = i-top;
                s.pop();
            }
            s.push(i);
        }
        
        return res;
    }
};