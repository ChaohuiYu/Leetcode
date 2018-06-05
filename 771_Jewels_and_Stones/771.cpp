class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> type(J.begin(), J.end());
        int count = 0;
        for (auto s:S)
            if (type.count(s)>0)
                ++count;
        return count;
    }
};