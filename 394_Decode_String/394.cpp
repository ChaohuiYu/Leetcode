class Solution {
public:
    string decodeString(string s) {
        
        stack<int> num_stack;
        stack<string> s_stack;
        string res = "";
        int num = 0;
        for(auto i:s)
        {
            if (i<='9' and i>='0')
            {
                num = num*10+(i-'0');
                
            }
            else if (i=='[')
            {
                num_stack.push(num);
                s_stack.push(res);
                num = 0;
                res ="";
            }
            else if (i==']')
            {
                int n = num_stack.top();
                num_stack.pop();
                string tmp = res;
                for (int j = 0; j < n -1 ; ++j)
                    res += tmp;
                res = s_stack.top() + res;
                s_stack.pop();
                
            }
            else if (isalpha(i))
            {
                res+=i;
            }
            
        }
        return res; 
    }
};
