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

int sumOfLeftLeaves(TreeNode* root) {
    if(!root || (!root->left && !root->right))
        return 0;

    int res_left = sumOfLeftLeaves(root->left);
    int res_right = sumOfLeftLeaves(root->right);

    if(root->left && (!root->left->left && !root->left->right))
        return res_left + res_right + root->left->val;
    else
        return res_left + res_right;
}
