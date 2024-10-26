#include "../headers.h" // IWYU pragma: keep

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root) {
    queue<Node*> que;

    if(root)
        que.push(root);

    while(!que.empty()){
        vector<Node*> level_vals;
        int level_nums = que.size();

        for(int i = 0; i < level_nums; ++i){
            auto node = que.front();
            que.pop();

            level_vals.push_back(node);
            if(node->left)
                que.push(node->left);
            if(node->right)
                que.push(node->right);
        }

        for(uint i = 0; i < level_vals.size()-1; i++){
            level_vals[i]->next = level_vals[i+1];
        }
    }

    return root;
}
