/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/

// CALL BY REF METHOD
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> m;
        for(const auto e:employees)
            m[e->id] = e;
        int sum = 0;
        DFS(m,id,sum);
        return sum;
    }
    void DFS(unordered_map<int, Employee*>& m, int id, int& sum)
    {
        sum+=m[id]->importance;
        for(const auto i:m[id]->subordinates)
            DFS(m,i,sum);
    }
};



class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        
        unordered_map<int,Employee*> sort_em;
        for (auto i:employees)
            sort_em[i->id] = i;
        return getImpact(sort_em,id);
    
    }
    int getImpact( unordered_map<int,Employee*> employees, int id){ 
        int impact = employees[id]->importance;
        for(auto i:employees[id]->subordinates)
            impact+=getImpact(employees,i);
        return impact;

    }
};


