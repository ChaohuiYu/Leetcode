

class Solution {
public:
    int reverse(int x) {
        
        bool flag = false;
        if (x < 0)
            x *= -1, flag = true;
        
        int num = 0;
        while (x){
            int tmp = num*10 + x%10;
            if (tmp / 10 != num)
                return 0;
            num = tmp;
            x /= 10;
        }
        
        return flag? (-1)*num : num;
        
    }
};
