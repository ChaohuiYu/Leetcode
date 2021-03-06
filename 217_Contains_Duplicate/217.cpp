class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashset;
        for (auto i:nums)
        {
            if (hashset.count(i)) return true;
            hashset.insert(i);
        }
        return false;
    }
};