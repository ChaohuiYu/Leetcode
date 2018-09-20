
class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x < 0)
            return false;
        
        int num = 0;
        int x1 = x;
        
        while(x){
            num = num*10 + x%10;
            x/=10;
        }
        
        if (num == x1)
            return true;
        else 
            return false;   
    }
};
