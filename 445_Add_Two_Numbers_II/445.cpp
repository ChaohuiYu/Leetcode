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
        
        stack<int> s1, s2;
        int carry = 0;
        while(l1){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        ListNode* prev = NULL;
        ListNode* n;
        while(!s1.empty() or !s2.empty() or carry){
            
            int sum = 0;
            sum = (s1.empty()? 0 : s1.top()) + (s2.empty()? 0 : s2.top()) + carry;
            carry = sum/10;
            n = new ListNode(sum%10);
            n->next = prev;
            if(!s1.empty()) s1.pop();
            if(!s2.empty()) s2.pop();
            prev = n;
        }
        return n;
    }
};
