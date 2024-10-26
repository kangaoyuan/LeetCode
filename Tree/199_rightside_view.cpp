#include <sys/types.h>
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

void dfs(TreeNode* root, uint depth, vector<int>& res){
    if(!root)
        return;
    if(res.size() == depth)
        res.push_back(root->val);
    dfs(root->right, depth+1, res);
    dfs(root->left, depth+1, res);
}

vector<int> rightSideView_(TreeNode* root) {
    vector<int> res;
    dfs(root, 0, res);
    return res;
}


vector<int> rightSideView__(TreeNode* root) {
    vector<int> res;
    queue<TreeNode*> que;
    if(root)
        que.push(root);

    while(!que.empty()){
        int level_nums = que.size();

        auto right_node = que.front();
        res.push_back(right_node->val);
        que.pop();
        if (right_node->right)
            que.push(right_node->right);
        if (right_node->left)
            que.push(right_node->left);

        for(int i = 1; i < level_nums; ++i) {
            auto node = que.front();
            que.pop();
            if(node->right)
                que.push(node->right);
            if(node->left)
                que.push(node->left);
        }
    }

    return res;
}
