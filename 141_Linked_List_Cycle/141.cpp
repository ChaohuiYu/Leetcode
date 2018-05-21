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
    bool hasCycle(ListNode *head) {
        if (head==NULL) return false;
        ListNode* cur=head->next;
        ListNode* prev=head;
        
        while(cur and prev and cur!=prev)
        {
            if(prev->next and cur->next) {prev = prev->next; cur=cur->next->next;}
            else break;

        }
        
        if (cur and prev and cur==prev) return true;
        else return false;
    
    }
};