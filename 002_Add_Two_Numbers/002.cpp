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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 or !l2) return l1? l1:l2;
        ListNode dummy = ListNode(0);
        ListNode * cur = &dummy;
        int sum = 0; 

        while (l1 or l2 or sum)
        {
            if (l1 and l2) sum += l1->val + l2->val;
            else if (l1 or l2) sum += l1? l1->val:l2->val;
            
            ListNode* tmp = new ListNode(sum%10); // ASK HERE
            cur->next = tmp;
            cur = cur->next;
            
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            sum /= 10;
        }
        return dummy.next;
    }
};