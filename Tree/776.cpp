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


vector<TreeNode*> splitBST(TreeNode* root, int target) {
    if(!root)
        return {nullptr, nullptr};

    if(target < root->val){
        auto split_left = splitBST(root->left, target);
        root->left = split_left[1];
        return {split_left[0], root};
    } else {
        auto split_right = splitBST(root->right, target);
        root->right = split_right[0];
        return {root, split_right[1]};
    }
}
