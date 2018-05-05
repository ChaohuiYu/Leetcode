[1,2,3] 
123 + 1
out: [1,2,4]
[9]
[1,0]

[9]
[9]
[1,0]

"9" + "1"
  

[1,2,3] ->[1, 2, 4]

"9" i +1
//hint: treat carry as the given 1 for summing up 

#66. Plus One
//my first thought
//bool carry = (digits[digits.end()]+1 >10) //<- bool carry = false; <- change it
vector<int> res;
bool carry = true;
//{
for (it=digits.end()-1:begin ) //<-
{
  
  if (carry)
  { 
    *it++;
    //check_if_carry(*it); // return carry; <-
  }
  //else //<-
  //{
  	  //check_if_carry(*it);// carry= true; *it=*it%10; [0] <-
  //}
  check_if_carry(*it);//here
}
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


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
    }
};