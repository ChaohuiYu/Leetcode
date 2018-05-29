
// My post: https://leetcode.com/problems/string-compression/discuss/134580/C++-easy-and-clean-solution-TC:O(N)-SC:O(1)


int compress(vector<char>& chars) {

    int count = 0, len = 0;
    char prev = 0;
   
    for (auto ch:chars)
    {
        if (prev==0 or ch==prev)  
            ++count;
        else
        {
            chars[len++] = prev;
            if(count>1)
                for (auto c_count:to_string(count))
                    chars[len++] = c_count;
            count = 1;
        }
        prev = ch;
    }
  
    // The last element
     chars[len++] = prev;
     if(count>1)
        for(auto c_count:to_string(count))
            chars[len++] = c_count;

    return len;
}


class Solution {
public:
    int compress(vector<char>& chars) {
    
        int count = 1, len = 0, i =1;
       
        for (;i<chars.size();++i)
        {
           if (chars[i]!=chars[i-1])
           {
               chars[len++] = chars[i-1]; 
               if(count>1)
                   for(auto ch:to_string(count))
                       chars[len++] = ch;
               count = 1;

           }
           else ++count;
        }
        
        // The last element
         chars[len++] = chars[i-1]; 
         if(count>1)
            for(auto ch:to_string(count))
                chars[len++] = ch;

        return len;
    }
};