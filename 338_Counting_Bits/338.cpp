// REF: http://www.cnblogs.com/grandyang/p/5315227.html

class Solution {
public:
    vector<int> countBits(int num) {
        
        vector<int> res(num+1);
        res[0] = 0;
        for(int i = 1; i <= num;++i)
        {
            if (i%2==0)
                res[i] = res[i/2];
            else
                res[i] = res[i/2] + 1;
        }
        
        return res;
    }
};



// trivial
class Solution {
public:
    vector<int> countBits(int num) {
        
        vector<int> res(num+1);
        for(int i = 0; i <= num;++i)
            res[i] = bitset<32>(i).count();
        
        return res;
    }
};
