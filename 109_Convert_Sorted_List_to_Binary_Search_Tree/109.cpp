/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        if (!head->next) return new TreeNode(head->val); 
        
        // Find Mid
        ListNode* slow = head, *fast = head;
        ListNode* prev = head;
        while (fast and fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
            
        }
        prev->next = NULL;
        
        TreeNode *root =  new TreeNode(slow->val); 
        root->right = sortedListToBST (slow->next);
        root->left  = sortedListToBST (head);
        
        return root;
    }
 
};