
// First thought, not neat enough  
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> stk;
        
        for (auto t:tokens)
        {
            if (t == "+" )
            {
                int o1 = stk.top(); stk.pop();
                int o2 = stk.top(); stk.pop();
                stk.push(o1+o2);
                
            }
            else if (t=="-")
            {
                int o1 = stk.top(); stk.pop();
                int o2 = stk.top(); stk.pop();
                stk.push(o2-o1);
                
            }
            else if (t=="*")
            {
                int o1 = stk.top(); stk.pop();
                int o2 = stk.top(); stk.pop();
                stk.push(o2*o1);
            }
            else if (t=="/")  
            {
                int o1 = stk.top(); stk.pop();
                int o2 = stk.top(); stk.pop();
                stk.push(o2/o1);
                
            }
            else 
                stk.push(stoi(t));
            
        }
        
        return stk.top();
    }
};
