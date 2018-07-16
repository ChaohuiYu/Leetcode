// First verison, doing a lots of pruning
// But the key cocept is to use stack `
class Solution {
public:
    string simplifyPath(string path) {
     
        stack<string> stk;
        string cur = "";
        
        for (auto p:path)
        {
            
            if (!cur.empty() and p=='/')
            {
                if (cur=="..")
                {
                    if (!stk.empty())
                        stk.pop();  
                }
                else if (cur!=".")
                {
                    stk.push(cur);
                }
                cur.resize(0);
                
            }
            
            if (p!='/')    
                cur+=p;
        }
        
        // Prune the last word
        if (cur=="..")
        {
            if (!stk.empty())
                stk.pop();
            cur.resize(0);
            
        }
        string res = cur.empty() or cur=="." ? "" : "/"+ cur; 
        
        
        //Pop the stack
        while (!stk.empty())
        {
            res = "/" + stk.top() + res;
            stk.pop();
        }
        
        // Prune the result
        return (res.empty() && path.find('/')>=0 )? "/" : res;
        
    }
};
