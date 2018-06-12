class Solution {
public:
    int countPrimes(int n) {
        
        if (n<=2) return 0;
        bool isPrime[n] ={0};
        auto cnt = 0;
        
        for (int i = 2; i<n; ++i){
            
            if(isPrime[i]==false)
            {
                ++cnt;
                isPrime[i]==true;
            }
            for (int j=2; i*j < n;++j)
            {
                isPrime[i*j] = true;
            }
        }
        
        
        return cnt;
    }
};