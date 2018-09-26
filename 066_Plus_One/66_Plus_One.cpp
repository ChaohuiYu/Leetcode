
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1, i = digits.size() - 1;
        
        while (i>=0){
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
            i--;
        }
        
        if (carry){
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       
        bool carry = true;
        int i = digits.size()-1; 
        
        while (i >=0)
        {
            if (carry) { ++digits[i]; carry = false;} 
            if (digits[i]>9) { digits[i]%=10; carry=true;}
            --i;
        }
      
        if (carry)  digits.insert(digits.begin(),1);
        return digits;
        
    }
};


// Note

// c: true
// n1: [9] 
// index i = n1.length - 1
// while (i >= 0 || c != false) {
//    1.sum = c;       1
//    2.output digit   1->[0]
//    3.carry          
// }
// <-
// <- if there still carry
// return 
//summation: 1.add strings, plus one, 2.add number, 3.add number ii
//
//while (n1 || n2 || c) {
//
//}
//if (carry)
//{
  //res[0] = 1;
  //res[1:n-1] = digits;
//}
//}
