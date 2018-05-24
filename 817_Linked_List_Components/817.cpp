/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
*/


// The biggest problem is what's the "connected component"

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        
        set<int> s(G.begin(), G.end());
        int res = 0;
        
        while (head)
        {
            if (s.count(head->val) and (!head->next or !s.count(head->next->val))) res++;
            head = head->next;
        }
        return res;
    }
};