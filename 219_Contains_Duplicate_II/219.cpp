
// My first soultion
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k<=0) return false;
        if (nums.empty()) return false;
        unordered_map<int,int> m;
        int dist=0;
        for (int i=0;i<nums.size();++i ){
            if ( m[nums[i]]!=0)
            {
                dist = (i+1)-m[nums[i]];
                if (dist<=k) return true;
            }
            m[nums[i]]=i+1;
        }
        return false;
    }
};