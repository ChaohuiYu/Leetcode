// O(2N) 
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
     
        stack<int> stk;
        for (auto  i : asteroids)
        {
            bool f = false;
            while (!stk.empty() and stk.top()>0 and  i*stk.top()<0)
            {
                f = true;
                if ( -i == stk.top())
                {
                    stk.pop(); break;
                }
                else if ( -i > stk.top() )
                    stk.pop(), f=false;
                else 
                    break;
            }
            
            if (f==false)
                 stk.push(i);
        }
        vector<int> res(stk.size());
        int i = stk.size() -1;
        while(i>=0)
        {
            res[i--] = stk.top();
            stk.pop();
        }
        return res;
    }
};
