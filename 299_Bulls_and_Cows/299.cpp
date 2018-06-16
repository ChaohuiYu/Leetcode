




// TC:O(2N) SC:O(N) 6ms in 152 test cases
class Solution {
public:
    string getHint(string secret, string guess) {
        
        int m[10] ={0}, no_A = 0, no_B = 0;
        vector<bool> checked (secret.size(),0);
        
        for (auto i = 0;i < secret.size();++i){
            
            m[secret[i]-'0']++;
            if (secret[i]==guess[i])
            {
                ++no_A;
                --m[secret[i]-'0'];
                checked[i] = 1;
            }
        }
        
        for (auto i=0;i<guess.size();++i)
        {
            if(!checked[i] and m[guess[i]-'0']!=0)
            { 
                ++no_B;
                --m[guess[i]-'0'];
            }
                
        }
        return to_string(no_A)+"A"+to_string(no_B)+"B";
    }
};