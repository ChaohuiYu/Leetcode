// Original thought 
class Solution {
public:
    int scoreOfParentheses(string S) {
        
        stack<int> st;
        int count = 0, ans = 0;
        
        for (auto i:S)
        {
            if(i=='(')
                st.push(-1);
            else if(i==')')
            {
                count = 0;
                while (st.top()>0)
                {
                    count+=st.top();
                    st.pop();
                }
                st.pop();
                count>0 ? st.push(count*2):st.push(1); 
            }
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};
