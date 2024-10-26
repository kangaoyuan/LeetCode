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

bool is_same_tree(TreeNode* left, TreeNode* right) {
    if (!left || !right)
        return left == right;

    bool node_res = (left->val == right->val);

    return node_res && is_same_tree(left->left, right->right) &&
           is_same_tree(left->right, right->left);
}
bool isSymmetric(TreeNode* root) {
    if(!root)
        return false;
    return is_same_tree(root->left, root->right);
}
