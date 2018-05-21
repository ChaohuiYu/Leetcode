/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Video reference: https://www.youtube.com/watch?v=kW7aIXyPbXI
// The concept is easy, but U need to be aware that the head might be removed,
// so I add a "dummy node" in front of the head

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy = ListNode(0);
        dummy.next = head;
        
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        
        for (int i=0;i<=n;++i)  fast = fast->next;
        
        while (fast)
        {
            fast = fast->next; 
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        return dummy.next;
        
    }
};