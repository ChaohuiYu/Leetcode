/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */



// Video reference: https://www.youtube.com/watch?v=AzWmks439Vc




// TWO PASS
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return head;
        RandomListNode dummy = RandomListNode(0), *r_cur = & dummy;
        RandomListNode* cur = head;
        map<RandomListNode*, RandomListNode*> m;
        RandomListNode* res_next;
        
        // copy the linked list and mapping 
        while (cur)
        {
           RandomListNode* res_next= new  RandomListNode(cur->label);
           m[cur] = res_next;
           r_cur->next = res_next;
           r_cur = res_next;

           cur = cur->next;
        }
        
        
        cur = head;
        while (cur)
        {
            m[cur]->random = m[cur->random];
            cur = cur->next;
        }
    
        return dummy.next;
        
    }
};e