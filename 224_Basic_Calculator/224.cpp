class Solution {
public:
    int calculate(string s) {
        int result= 0;
        int sign = 1;
        int num  = 0;
        
        stack<int> st;
        
        for (auto ch:s)
        {
            if (ch<='9' and ch>='0')
            {
                num = num*10 + ch-'0';
            }
            else
            { 
                result += sign*num;
                num = 0;
                if (ch=='+') sign = 1;
                if (ch=='-') sign = -1;
                if (ch=='(')
                {
                    st.push(result);
                    st.push(sign);
                    result = 0;
                    sign = 1;
                }
                if (ch==')')
                {
                    result = result * st.top();
                    st.pop();
                    result += st.top();
                    st.pop();
                }
            }
        }
        result += num*sign;
        return result;
        
    }
};