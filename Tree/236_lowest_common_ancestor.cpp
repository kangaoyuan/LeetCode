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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root)
        return nullptr;
    if(p == root || q == root)
        return root;

    auto* res_left = lowestCommonAncestor(root->left, p, q);
    auto* res_right = lowestCommonAncestor(root->right, p, q);

    if(!res_left)
        return res_right;
    if(!res_right)
        return res_left;

    return root;
}
