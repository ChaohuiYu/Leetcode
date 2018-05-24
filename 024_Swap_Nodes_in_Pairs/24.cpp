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
    ListNode* swapPairs(ListNode* head) {
     
        if (!head or !head->next) return head;
        ListNode *p1 = head, *p2 = head->next, *tmp = NULL, *new_head = head->next;
        
        while(p1 and p2 and p1!=p2)
        {
            
            if (p2->next and p2->next->next) p1->next = p2->next->next;
            else p1->next = p2->next;
            tmp = p2->next;
            p2->next = p1; 
           
            p2 = p1->next;
            p1 = tmp;
        }
        
        return new_head;
       
    }

};