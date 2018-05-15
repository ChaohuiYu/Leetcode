// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        if (n==1)  return 1;
        int l=1, r=n, mid;
        
        while (l<r)
        {
            mid = l+(r-l)/2;
            if (isBadVersion(mid)) r = mid;
            else l = mid+1 ;       
        }

        return r; // Why both L and R work ?? Stop condition:  l is equal to r !!!!!!
    }
};