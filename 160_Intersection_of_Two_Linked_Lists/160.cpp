/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// video reference: https://www.youtube.com/watch?v=_7byKXAhxyM

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA or !headB) return NULL;
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0;
        int lenB = 0;
        
        // Calculate the length
        while(curA) {++lenA;curA = curA->next;}
        while(curB) {++lenB;curB = curB->next;}
        
        curA = headA; curB = headB;
        
        // Calulate the distance and move the pointer
        if (lenA-lenB>=0)
        {
            int d = lenA-lenB;
            for (int i=0;i<d;++i) curA = curA->next;
        }
        else
        {
            int d = lenB-lenA;
            for (int i=0;i<d;++i) curB = curB->next;
        }
        
        // move two pointers 
        while(curA)
        {
            if(curA==curB) return curA;
            curA = curA->next;
            curB = curB->next;
        }
       
        return NULL;
    }
};