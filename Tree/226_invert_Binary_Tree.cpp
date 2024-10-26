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

TreeNode* invertTree(TreeNode* root) {
    if (root == NULL)
        return nullptr;

    swap(root->left, root->right);

    invertTree(root->left);
    invertTree(root->right);

    //swap(root->left, root->right);

    return root;
}

TreeNode* invertTree_(TreeNode* root) {
        if (!root)
            return nullptr;

        auto left = invertTree(root->left);
        auto right = invertTree(root->right);

        root->left = right;
        root->right = left;

        return root;
}
