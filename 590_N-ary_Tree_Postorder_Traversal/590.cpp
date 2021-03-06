
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
    vector<int> postorder(Node* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
    
    void traversal(Node* n, vector<int> &res)
    {
        if (!n)
            return;

        for (auto i:n->children)
            traversal(i, res);    
        
        res.push_back(n->val);
    }
};
