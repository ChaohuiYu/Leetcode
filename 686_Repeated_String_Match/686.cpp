class Solution {
public:
    
    // abcdabcd 
    // cdabcdab
    // https://www.youtube.com/watch?v=tm0p3KE0KE8
    int repeatedStringMatch(string A, string B) {
        
        string str = A;;
        int count = 1;
        while (str.length()<B.length()){
            str+=A;
            ++count;
        }
        
        if (str.find(B)!=string::npos) return count;
        else{
            str+=A;
            ++count; 
            if (str.find(B)!=string::npos) return count;
            else return -1;
        }
    
    }
};