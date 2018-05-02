/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */




// Iteravtive: Use two other pointers to track
//Your runtime beats 98.94 % of cpp submissions.



class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* cur=head; 
        ListNode* next=NULL; 
        ListNode* prev=NULL;
        
        while (cur)
        {
            next=cur->next;
            cur->next = prev;
            prev = cur; cur = next; // move to next node
        }
        
        return prev;
        
    }
};



// First thought: TLE
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        stack<ListNode*> nodestack;
        while (head)
        {
            nodestack.push(head);
            head=head->next;
        }
        
        head = nodestack.top();
        nodestack.pop();
        
        while(!nodestack.empty())
        {
            head->next=nodestack.top();
            
            nodestack.pop();
            
        }
        
        return head;
    }
};