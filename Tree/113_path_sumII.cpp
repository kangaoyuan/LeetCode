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

vector<int>         path;
vector<vector<int>> res;

void dfs(TreeNode* root, int targetSum) {
    if (!root)
        return;
    if (!root->left && !root->right && targetSum == root->val) {
        path.push_back(root->val);
        res.push_back(path);
        path.pop_back();
        return;
    }

    int node_val = root->val;

    path.push_back(node_val);
    dfs(root->left, targetSum - node_val);
    dfs(root->right, targetSum - node_val);
    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    dfs(root, targetSum);
    return res;
}
