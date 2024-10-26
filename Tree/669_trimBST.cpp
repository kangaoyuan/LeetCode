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

/*
 *TreeNode* trimBST(TreeNode* root, int low, int high) {
 *    if (root == nullptr)
 *        return nullptr;
 *
 *    if(root->val < low)
 *        return trimBST(root->right, low, high);
 *
 *    if(root->val > high)
 *        return trimBST(root->left, low, high);
 *
 *    root->left = trimBST(root->left, low, high);
 *    root->right = trimBST(root->right, low, high);
 *
 *    return root;
 *}
 */

TreeNode* trimBST(TreeNode* root, int low, int high) {
    while (root && (root->val < low || root->val > high)) {
        if (root->val < low) {
            root = root->right;
        } else {
            root = root->left;
        }
    }

    if (!root)
        return nullptr;

    TreeNode* tree = root;
    while (tree->left) {
        if (tree->left->val < low) {
            tree->left = tree->left->right;
        } else {
            tree = tree->left;
        }
    }

    tree = root;
    while (tree->right) {
        if (tree->right->val > high) {
            tree->right = tree->right->left;
        } else {
            tree = tree->right;
        }
    }
    return root;
}
