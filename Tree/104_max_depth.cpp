#include "../headers.h" // IWYU pragma: keep

struct TreeNode {
    int       val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

// dfs
int maxDepth(TreeNode* root) {
    if(!root)
        return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// bfs
int maxDepth_(TreeNode* root) {
    if(!root)
        return 0;

    queue<TreeNode*> que;
    que.push(root);
    int cnt = 0;

    while(!que.empty()){
        cnt++;
        int level_nums = que.size();
        for(int i = 0; i < level_nums; ++i){
            auto node = que.front();
            que.pop();
            if(node->left)
                que.push(node->left);
            if(node->right)
                que.push(node->right);
        }
    }

    return cnt;
}
