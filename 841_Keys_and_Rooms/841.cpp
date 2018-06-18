
// Iterative way:10ms in 66 test cases 
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        stack<int> dfs;dfs.push(0);
        unordered_set<int> visited = {0};
        
        while(!dfs.empty())
        {
            int i = dfs.top(); dfs.pop();
            for (auto j:rooms[i])
               if (visited.count(j)==0)
               {
                   dfs.push(j);
                   visited.insert(j);
                   if (visited.size()==rooms.size()) return true;
               }   
        }
        return visited.size()==rooms.size();
    }
};



// 10ms in 66 test cases
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        vector<bool> visited(rooms.size(), false);
        visitroom(rooms, visited, 0);
        
        for (auto i:visited)
            if (!i) return false;
        return true;
    }
    
    void visitroom(vector<vector<int>>& room, vector<bool>& visited, int idx )
    {
        visited[idx] = true;
        if(room[idx].empty()) return ;
        
        for (auto i:room[idx]){
            if (!visited[i])
                visitroom(room,visited,i);
        }
    }
};