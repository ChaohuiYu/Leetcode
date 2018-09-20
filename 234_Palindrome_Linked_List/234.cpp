
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
    bool isPalindrome(ListNode* head) {
        
        if (!head) return true;
        if (!head->next) return true;
        
        // Find the mid
        ListNode* fast = head, *slow = head, *prev =NULL;
        
        while(fast and fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        
        // For odd linked list
        if (fast) slow = slow->next;
    
        ListNode* tmp = reverse(slow);
        while (tmp)
        {
            if (tmp->val==head->val){
                tmp = tmp->next;
                head = head->next;
            }
            
            else return false;
        }
        
        return true;
      
        
    }
    
    ListNode* reverse(ListNode* node)
    {
        ListNode* cur = node, *prev =NULL, *fast;

        while (cur)
        { 
            fast = cur->next;
            cur->next = prev;
            prev = cur;
            cur = fast;
        }
        return prev;
    }
};



// Naive solution
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        if (!head) return true;
        if (!head->next) return true;
        
        // Find the mid
        ListNode* fast = head, *slow = head, *prev =NULL;
        
        while(fast and fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        
        // For odd linked list
        if (fast) slow = slow->next;
    
        ListNode* tmp = reverse(head);
        while (tmp and slow)
        {
            if (tmp->val==slow->val){
                tmp = tmp->next;
                slow = slow->next;
            }
            
            else return false;
        }
        
        if (!tmp and !slow) return true;
        else return false;
        
    }
    
    ListNode* reverse(ListNode* node)
    {
        ListNode* cur = node, *prev =NULL, *fast;

        while (cur)
        { 
            fast = cur->next;
            cur->next = prev;
            prev = cur;
            cur = fast;
        }
        return prev;
    }
};
