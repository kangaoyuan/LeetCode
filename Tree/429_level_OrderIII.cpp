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

vector<vector<int>> levelOrder(Node* root) {
    queue<Node*> que;
    vector<vector<int>> res;

    if(root)
        que.push(root);

    while(!que.empty()){
        vector<int> level_vals;
        int level_nums = que.size();

        for(int i = 0; i < level_nums; ++i){
            auto node = que.front();
            que.pop();

            level_vals.push_back(node->val);

            for(uint j = 0; j < node->children.size(); j++){
                if(node->children[j])
                    que.push(node->children[j]);
            }
        }

        res.push_back(level_vals);
    }

    return res;
}
