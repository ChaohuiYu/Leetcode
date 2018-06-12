

// 18 ms PQ 
class Solution {
    
private:
    struct comp{
        comp(){};
        ~comp(){};
        bool operator () (const pair<string, int> &a, const pair<string, int>& b){
            return a.second<b.second or (a.second==b.second and a.first>b.first);
        }
    };
        
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        vector<string> res;
        
        for (auto i:words)
            ++m[i];
        
        // PQ 
        priority_queue<pair<string, int>, vector<pair<string, int>>, comp> pq;
        for (auto i:m)
            pq.push(i);
        
    
        for (int i =0;i<k;++i)
        {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;

    
    }
};




// 17ms 110 test cases
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        vector<string> res;
        
        for (auto i:words)
            ++m[i];
        // bucket sort
        vector<vector<string>> v (words.size()+1);
        
        for(auto i:m){
            v[i.second].push_back(i.first);
            sort( v[i.second].begin(),  v[i.second].end());
        }
        
        
    
        for (auto it = v.rbegin();it!=v.rend();++it){

                for(auto j:*it)
                    if (res.size()!=k)
                        res.push_back(j);
        }
        
        return res;

    }
};