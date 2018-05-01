class Solution {
public:
    char findTheDifference(string s, string t) {
        
        int result=0;
        int i=0;
        
        int size = s.size();
        cout<<"size"<<size;
        
        
        
        for (;i<s.size();i++)
        {
            cout<<i<<",";
            
            result^=(s[i]-'a');
            result^=(t[i]-'a');
        }
        
        result^=(t[i]-'a');
        return result+'a';
    }
};