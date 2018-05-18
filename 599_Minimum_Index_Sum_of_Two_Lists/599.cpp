
// Concise One
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string>res;
        unordered_map<string,int>m;
        int min = INT_MAX;
        for(int i = 0; i < list1.size(); i++) m[list1[i]] = i;
        for(int i = 0; i < list2.size(); i++)
            if(m.count(list2[i]) != 0)
                if(m[list2[i]] + i < min) min = m[list2[i]] + i, res.clear(), res.push_back(list2[i]);
                else if(m[list2[i]] + i == min) res.push_back(list2[i]);
        return res;
    }

// First Thought 
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> map;
        int least_one = INT_MAX; vector<string> restaurant;
        for (int i=0;i<list1.size();++i)     map[list1[i]]+=i+1; 
        for (int i=0;i<list2.size();++i)   
            if(map[list2[i]]>0)
            {
                map[list2[i]]+=i;
                if (map[list2[i]]<least_one) { least_one=map[list2[i]]; 
                                              restaurant.resize(0);restaurant.push_back(list2[i]);}
                else if (map[list2[i]]==least_one){restaurant.push_back(list2[i]);}
            }
        return restaurant;  
    }
};