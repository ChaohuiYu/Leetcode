/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode *prev = NULL, *cur = head;
        
        while (cur)
        {
            if (prev and cur and cur->val==prev->val){ prev->next = cur->next; cur = cur->next;}
            else {prev = cur; cur = cur->next;}
        }
        return head;
    }
};