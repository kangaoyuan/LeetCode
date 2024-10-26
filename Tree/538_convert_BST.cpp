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

void dfs(TreeNode* root, int& pre){
    if(!root)
        return;

    dfs(root->right, pre);
    root->val += pre;
    pre = root->val;
    dfs(root->left, pre);
}

TreeNode* convertBST(TreeNode* root) {
    int pre = 0;
    dfs(root, pre);
    return root;
}



/*
 *int  pre = 0;
 *void dfs(TreeNode* root) {
 *    if (!root)
 *        return;
 *
 *    dfs(root->right);
 *    root->val += pre;
 *    pre = root->val;
 *    dfs(root->left);
 *}
 *
 *TreeNode* convertBST(TreeNode* root) {
 *    dfs(root);
 *    return root;
 *}
 */
