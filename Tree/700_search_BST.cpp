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

TreeNode* searchBST(TreeNode* root, int val) {
    if (!root || root->val == val)
        return root;
    if (root->val < val)
        return searchBST(root->right, val);
    else
        return searchBST(root->left, val);
}

void dfs(TreeNode* root, TreeNode** res, int val) {
    if (!root)
        return;
    if (root->val == val) {
        *res = root;
        return;
    } else if (root->val < val) {
        dfs(root->right, res, val);
    } else {
        dfs(root->left, res, val);
    }
}

TreeNode* searchBST_(TreeNode* root, int val) {
    TreeNode* res = nullptr;

    dfs(root, &res, val);

    return res;
}
