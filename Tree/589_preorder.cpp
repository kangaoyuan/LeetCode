#include "../headers.h" // IWYU pragma: keep

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

void dfs(Node* root, vector<int>& res) {
    if(!root)
        return;

    res.push_back(root->val);

    for(uint i = 0; i < root->children.size(); ++i){
        if(root->children[i])
            dfs(root->children[i], res);
    }
}

vector<int> preorder(Node* root) {
    vector<int> res;
    dfs(root, res);

    return res;
}
