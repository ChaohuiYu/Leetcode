
// Concise one 

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string s = "";
        int c = 0, i = a.size() - 1, j = b.size() - 1;

        while(i >= 0 || j >= 0 || c == 1)
        {
            c += i >= 0 ? a[i --] - '0' : 0;
            c += j >= 0 ? b[j --] - '0' : 0;
            s = char(c % 2 + '0') + s;
            c /= 2;
        }
        
        return s;
    }
};



//  First thought
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1;
        int j = b.size()-1;
        bool c = false;
        string res="";
        
        while (i>=0 or j>=0 or c)
        {
            int sum = 0;
            
            if (c) { sum+=1; c = false;}
            if (i>=0){ sum+=(a[i]-'0'); --i;}
            if (j>=0){ sum+=(b[j]-'0'); --j;}
            
            if (sum>1) c = true; 
            res = char(sum%2+'0')+ res;        // Be careful!!
        }
        return res;
        
    }
};