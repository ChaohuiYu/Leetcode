// One Pass
class solution{
public:
	int calPoints(vector<string& ops){
		stack<int> s;
        int sum = 0; 
        
        for (auto i:ops)
        {   
            if (i == "C")
            {
                sum-=s.top();
                s.pop();
                continue;
            }
               
            else if(i == "D")
            {
                s.push(s.top()*2);
                sum += s.top();
                
            }
                
            else if(i == "+")
            {
                int l1 = s.top();
                s.pop();
                int l2 = s.top();
                s.push(l1);
                s.push(l1+l2);
                sum+=l1+l2;
            }
            else 
            {
                s.push(stoi(i));
                sum += stoi(i);
            }
        }
        
        return sum;	
	}
};


// TWO PASS 
class Solution {
public: 
    int calPoints(vector<string>& ops) {
        stack<int> s;
        int res = 0;
        
        for (auto i:ops)
        {        
            if (i == "C")
                s.pop();
            else if(i == "D")
                s.push(s.top()*2);
            else if(i == "+")
            {
                int l1 = s.top();
                s.pop();
                int l2 = s.top();
                s.push(l1);
                s.push(l1+l2);
            }
            else 
                s.push(stoi(i));
        }
        
        while(!s.empty())
        {
            res+=s.top();
            s.pop();
        }
        
        return res;
    }
};

