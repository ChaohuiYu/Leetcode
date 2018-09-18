
class Solution {
public:
    void reverseWords(string &s) {
        
        stack<string> st;
        
        string tmp;
        
        for (auto i:s){
            if (i != ' ')
                tmp += i;
            else{
                if (!tmp.empty()) st.push(tmp);
                tmp.resize(0);
            }
                
        }
        // the last word
        if(!tmp.empty())
            st.push(tmp);
        
        s.resize(0);
        while(!st.empty()){
            s+=st.top();
            st.pop();
            if(!st.empty()) s+=' ';
        }
    }
};
