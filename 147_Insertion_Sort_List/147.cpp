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
    ListNode * insertionSortList(ListNode* head) {
        if (!head or !head->next) return head;
        ListNode dummy = ListNode(0), *tail = &dummy, *tmp = &dummy;
        
        while(head)
        {
            tmp = &dummy;
            
            while (tmp and tmp->next and tmp->next->val < head->val )
               tmp = tmp->next;
            
            tail = tmp->next;
            tmp->next = head;
            head = head->next;
            tmp->next->next = tail;
        }
        
        return dummy.next;
    }
};