class Solution {
public:
    int calculate(string s) {
        
        stack<int> stack;
        int num = 0, tmp = 0, result = 0;
        char sign = '+';
        
        for (int i=0;i<s.length();++i)
        {
            if (isdigit(s[i]))
            {
                num = num*10+s[i]-'0';
            }
            
            if (!isdigit(s[i]) and s[i]!=' ' or i==s.length()-1)
            {
             
               if (sign=='*' or sign=='/')
               {
                   if (sign=='*') tmp = stack.top() * num;
                   else tmp = stack.top()/num;
                   stack.pop();
                   stack.push(tmp);
                   
               }

               if (sign=='+')
                    stack.push(num);
               if (sign=='-')
                   stack.push(-num);
              sign = s[i];
              num = 0;
            }
                
        }
        
        while (!stack.empty()){   
             result += stack.top();
             stack.pop();
        }
        return result;
    }
};