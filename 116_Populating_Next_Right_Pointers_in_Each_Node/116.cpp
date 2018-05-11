/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */


// Very Smart Answer! SC:O(1)

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        TreeLinkNode* prev = root;
        TreeLinkNode* cur;
        
        while (prev->left)
        {
            cur = prev;
            while (cur)
            {
                cur->left->next = cur->right;
                if (cur->next)  cur->right->next = cur->next->left;
                cur = cur->next;
            }
            prev = prev->left;
        }
    }
};

class Solution {
public:
    void connect(TreeLinkNode *root)
    {
        queue<TreeLinkNode*> treeQueue;
        if (!root) return;
        else { treeQueue.push(root); treeQueue.push(NULL);} // marker!
        
        TreeLinkNode* prev = NULL;
        TreeLinkNode* cur = NULL;
    
        while (!treeQueue.empty())
        {
            // Connect!
            prev = cur;
            cur = treeQueue.front();  treeQueue.pop();
            if (prev) prev ->next = cur;
            
            // Same as LEVEL order!
            if (!cur)
            {
                if (treeQueue.size()>0) treeQueue.push(NULL);    // PUT ON marker!
            }
            else
            {
                if (cur->left) treeQueue.push(cur->left);
                if (cur->right) treeQueue.push(cur->right);
            }
            
        }
    }
   
};