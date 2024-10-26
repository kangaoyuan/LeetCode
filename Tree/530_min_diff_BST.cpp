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

int min_diff = INT_MAX;
TreeNode* pre = nullptr;

int getMinimumDifference(TreeNode* root) {
    if(!root)
        return 0;

    getMinimumDifference(root->left);

    if(pre)
        min_diff = min(min_diff, root->val - pre->val);

    pre = root;

    getMinimumDifference(root->right);

    return min_diff;
}
