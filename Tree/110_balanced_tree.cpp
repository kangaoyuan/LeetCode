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

int get_height(TreeNode* root) {
    if (!root)
        return 0;

    int height_left = get_height(root->left);
    if (height_left == -1)
        return -1;

    int height_right = get_height(root->right);
    if (height_right == -1)
        return -1;

    int node_res = abs(height_left - height_right);
    if (node_res > 1)
        return -1;

    return max(height_left, height_right) + 1;
}

bool isBalanced(TreeNode* root) {
    return get_height(root) != -1;
}
