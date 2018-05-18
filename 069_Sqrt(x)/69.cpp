class Solution {
public:
    int mySqrt(int x) {
          
        if (x<2) return x;

        int l=0, r=x;
        int mid, ans;
        
        while (l<=r)
        {
            mid = l+(r-l)/2;
            if (mid<=x/mid) { l=mid+1; ans=mid;}
            else r=mid-1;
        }
        return ans;
    
    }
};