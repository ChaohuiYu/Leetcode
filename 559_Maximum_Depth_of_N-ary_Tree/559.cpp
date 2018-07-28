
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
    int maxDepth(Node* root) {
        
        return findDepth(root, 1);
    }
    
    int findDepth(Node* n, int d)
    {
        if (!n)
            return d-1;
        
        int res = d;
        for (auto i:n->children)
        {
            
            res = max(res, findDepth(i, d+1));
        }
        return res;
    }
};
