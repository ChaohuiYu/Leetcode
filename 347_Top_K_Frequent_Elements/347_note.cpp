https://leetcode.com/problems/merge-k-sorted-lists/ (max heap, best solution divide and conquer) //<=====
https://leetcode.com/problems/merge-two-sorted-lists/description/ <========== 
Given [1,1,1,2,2,3] and k = 2, return [1,2].
1: 3 1st
2: 2 2nd
3: 1
k = 2 top k frequent element

/*
struct CmpByKeyLength {  
  bool operator()(const string& k1, const string& k2) {  
    return k1.length() < k2.length();  
  }  
};
int main() {  
  map<string, int, CmpByKeyLength> name_score_map;  
  name_score_map["LiMin"] = 90;   
  name_score_map["ZiLinMi"] = 79;   
  name_score_map["BoB"] = 92;   
  name_score_map.insert(make_pair("Bing",99));  
  name_score_map.insert(make_pair("Albert",86));  
  for (map<string, int>::iterator iter = name_score_map.begin();  
       iter != name_score_map.end();  
       ++iter) {  
    cout << *iter << endl;  
  }  
  return 0;  
} 
Output: 
BoB 92
Bing 99
LiMin 90
Albert 86
ZiLinMi 79
*/
//0. construct the frequency map first (freqency map1 key: element in nums, value: occurence freqency)
//1. declar compare struct
//2. iterate map1 to construct the map2 (map2 key: frequency value: list of elements)
//3. output k elements from the map2
       5 <=======
      / 
     4
    /
   3
  /
 2   O(N)  not O(logN) 
// [3,1,2,4,5]  assure each element [1,5]   [1][2][3][4][5] <===== 
// O(N) bucket sort   O(NlogN)    when you use bucket sort you need to assure the element's range
// [1,1,1,1,1,1,1] largest freqency will be size of the nums
      vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        if (!nums.size()) return res;
        unordered_map<int, int> cnt;
        for (auto num : nums) cnt[num]++;      // <== build up frequency map
        vector<vector<int>> bucket(nums.size() + 1); //<=== key point: frequency range [1, nums.size()] <=====
        // bucket[0] is a dummy because there's no frequency 0 will be stored in unordered_map cnt
        // that's why we need +1
      for (auto kv : cnt) {
            bucket[kv.second].push_back(kv.first);   
        }

        for (int i = bucket.size() - 1; i >= 0; --i) {
            for (int j = 0; j < bucket[i].size(); ++j){
                res.push_back(bucket[i][j]);
                if (res.size() == k) return res;
            }
        }

        return res;
    }
  https://leetcode.com/problems/top-k-frequent-elements/discuss/81631/3-ways-to-solve-this-problem  
https://leetcode.com/problems/top-k-frequent-elements/discuss/81635/3-Java-Solution-using-Array-MaxHeap-TreeMap (java)
vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> res;
        if (num.empty() or k==0) return res;
        map<int, int> map1;      //<=== use this map to store frequency   
        map<int, queue<int>, Cmp> map2 //<=========== sorted map         c++   java (TreeMap) => red black tree (binary search tree) add/remove O(logN)
      
        // build up this freq map                      //<== O(N)
        for (auto i:nums)           
          ++map1[i];
        for (auto it=map1.begin();it!=map1.end();++it)  ///<==== O(N*logN)
        {
          map2[*(it->second)].push(*(it->first));
        }
        //[1,1,1,2,2,2,3] => k=1 [1] or [2]  k=2 [1,2]
        k=2 
        // Output the top K element <====
        // iterate the amp
        for (auto it=map2.begin(); it!=map2.end() && k > 0; ++it) {    //<==== O(K)
          while (entry's value (vector) is not empty && k > 0) {
              res.push_back(pop up 1 element from the vector and push back to res);
                k--;
            }
        }
        return res;
        
        while (auto it=map2.begin();it!=map2.end() && k>0; ++it){
          while (!*(it->second).empty() and k>0)
            {
              res.push_back(*(it->second).front());
                *(it->second).pop();
                k--;
            }
        }         
        
 }
struct Cmp {
bool operator()(const int& k1, const int& k2){
  return k1>k2;
} //<==== order DESC: higher frequency be in front of lower frequency
}

struct CmpByKeyLength {  
  bool operator()(const string& k1, const string& k2) {  
    return k1.length() < k2.length(); // <===== k1 len < k2 len return true  k1 be in front of k2
  }  
  bool operator()(const string& k1, const string& k2) {  
    return k2.length() < k1.length(); // <===== k1 len < k2 len return false  k2 be in front of k1
  }
};
  
  
  