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
    ListNode* oddEvenList(ListNode* head) {
        // Trivial Thing 
        if (!head or !head->next) return head;
        ListNode dummy_odd = ListNode(0); 
        ListNode dummy_even = ListNode(0);
        dummy_odd.next = &dummy_even; dummy_even.next = head;
        ListNode* p_odd = &dummy_odd;
        ListNode* p_even = &dummy_even;
        
        while (p_odd and p_even)
        {
            if (p_odd->next->next){
                p_odd->next = p_odd->next->next;
                p_odd = p_odd->next;
            }
            else break;
            
            if (p_even->next){
                p_even->next = p_even->next->next;
                p_even = p_even->next;
            }  
        }
        // Connect
        p_odd->next = dummy_even.next;
        return dummy_odd.next;    
    }
};