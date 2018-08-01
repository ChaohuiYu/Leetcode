
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        
        if (!root) return {};
        vector<int> res;
        stack<Node*> stk;
        stk.push(root);
        
        while(!stk.empty())
        {
            Node* curNode = stk.top();
            stk.pop();
            res.push_back(curNode->val);
            
            for (int i = curNode->children.size() - 1; i >= 0; --i)
            {
                if(curNode->children[i] != NULL)
                    stk.push(curNode->children[i]);
            }
            
        }
        return res;
    }
};
