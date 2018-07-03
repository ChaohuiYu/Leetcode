

class Solution {
public:
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        
       return DFS(price,special,needs,0);
    }
    
    int DFS(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int cost)
    {
        if(compare(needs,0))
            return INT_MAX;
        
        int m = Multiply(price,needs)+cost;
        
        for (auto offer:special){
        
            if(cost+offer.back()>m)
                continue;
            Minus(needs,offer);
            m= min(m,DFS(price,special,needs,cost+offer.back()));
            Add(needs,offer);
        }
        return m;
        
    }
    
    bool compare(const vector<int> &a, const int &n) {
        for (int i : a)
            if (i < n)
                return true;
        return false;
    }

    void Add(vector<int>& a, const vector<int>&b)
    {
        for(int i=0;i<a.size();++i)
        {
            a[i]+=b[i];
        }
    }

    void Minus( vector<int>& a, const vector<int>&b)
    {
        for(int i=0;i<a.size();++i)
        {
            a[i]-=b[i];
        }
    }

    int Multiply(const vector<int>& a, const vector<int>&b)
    {
        int res = 0;
        for(int i=0;i<a.size();++i)
        {
           res+=a[i]*b[i];
        }
        return res;
    }
    
};