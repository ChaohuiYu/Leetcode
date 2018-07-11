//One container 
class MinStack {
    stack<int> s;
    int min;
public:
    /** initialize your data structure here. */
    MinStack() {
        min = INT_MAX;
    }
    
    void push(int x) {
        
        if(x <= min) // Need to be aware of "="
        {
            s.push(min);
            min = x;
        }
        s.push(x);
    }
    
    void pop() {
        if (s.top()==min)
        {
            s.pop();
            min = s.top();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min;
    }
};

// Two containers 
class MinStack {
    vector<int> v1;
    vector<int> v2;
    
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        v1.push_back(x);
        if(v2.empty()) v2.push_back(x);
        else v2.push_back(x < v2.back()? x : v2.back());
    }
    
    void pop() {
        
        v1.pop_back();
        v2.pop_back();
    }
    
    int top() {
        return v1.back();
    }
    
    int getMin() {
        return v2.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */


