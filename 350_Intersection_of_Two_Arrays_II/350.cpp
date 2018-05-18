



/****
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
***/


1.	If only nums2 cannot fit in memory, put all elements of nums1 into a HashMap, 
read chunks of array that fit into the memory, and record the intersections.

2. If both nums1 and nums2 are so huge that neither fit into the memory, 
sort them individually (external sort), then read 2 elements from each array at a time in memory, 
record intersections.

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