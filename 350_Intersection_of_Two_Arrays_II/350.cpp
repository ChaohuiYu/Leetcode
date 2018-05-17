



/****
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
***/


// First thought;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> res;
        if (!nums1.size() or !nums2.size()) return res;
        unordered_map<int, int> m;
        for(auto i:nums1) m[i]++;
        for(auto i:nums2)
            if (m[i])  { --m[i]; res.push_back(i);}
        return res;
    }
};