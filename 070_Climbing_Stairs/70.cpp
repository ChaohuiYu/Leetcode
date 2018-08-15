class Solution {
public:
    int climbStairs(int n) {
        
        if (n <= 2) return n;
        int s0 = 0, s1 = 1, s2 = 2;
        
        for (int i = 2;i < n ;++i){
            s0 = s1;
            s1 = s2;
            s2 = s1 + s0;
        }
        return s2;
    }
};
