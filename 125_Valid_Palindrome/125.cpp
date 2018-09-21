

class Solution {
public:
    bool isPalindrome(string s) {
        
        if (s.length() == 0) return true;
        
        for ( int l = 0, r = s.length() -1; l < r; ++l, --r){
            while(!isalnum(s[l]) and l < r) l++;
            while(!isalnum(s[r]) and l < r) r--;
            
            if (tolower(s[l]) != tolower(s[r]))
                return false;
        }
        return true;
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() == 0) return true;
        transform(s.begin(), s.end(), s.begin(), ::tolower); 
        
        int l = 0, r = s.length()-1;
        
        while ( l <= r ){
            
            while (!isalnum(s[l])) l++;
            while (!isalnum(s[r])) r--;
            
            if (l > r) return true;
            
            if (s[l] != s[r])
                return false;
            else
                l++, r--;
            
            
        }
        
        return true;
    }
};
