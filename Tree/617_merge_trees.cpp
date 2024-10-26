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

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (!root1)
        return root2;
    if (!root2)
        return root1;

    root1->val += root2->val;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);

    return root1;
}

TreeNode* mergeTrees_(TreeNode* root1, TreeNode* root2) {
    if(!root1 && !root2)
        return nullptr;

    int node_val = 0;
    if(!root1 && root2)
        node_val = root2->val;
    else if(!root2 && root1)
        node_val = root1->val;
    else
        node_val = root1->val + root2->val;

    TreeNode* root = new TreeNode(node_val);

    TreeNode *left1, *left2, *right1, *right2;
    if (!root1) {
        left1 = right1 = nullptr;
    } else {
        left1 = root1->left;
        right1 = root1->right;
    }

    if (!root2) {
        left2 = right2 = nullptr;
    } else {
        left2 = root2->left;
        right2 = root2->right;
    }

    root->left = mergeTrees(left1, left2);
    root->right = mergeTrees(right1, right2);

    return root;
}
