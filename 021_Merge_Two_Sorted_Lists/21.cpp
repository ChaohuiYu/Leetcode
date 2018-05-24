/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


// Concise version
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy = ListNode(0), *cur = &dummy;
        
        while (l1 and l2)
        {
            if (l1->val<=l2->val){ cur->next = l1; l1 = l1->next;}
            else { cur->next = l2; l2 = l2->next;}
            cur = cur->next;
        }
        
        cur->next = l1? l1:l2;
        return dummy.next;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode dummy = ListNode(0), *res = &dummy;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        
        while (cur1 or cur2)
        {
            if (!cur1 and cur2) { res->next = cur2; cur2 = cur2->next;}
            else if  (cur1 and !cur2) { res->next = cur1; cur1 = cur1->next;}
            
            else if (cur1->val<=cur2->val) { res->next = cur1; cur1 = cur1->next;}
            else  { res->next = cur2;  cur2 = cur2->next;}
            
            res = res->next;
        }
        
        return dummy.next;
    }
};