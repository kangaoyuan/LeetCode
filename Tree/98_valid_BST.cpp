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

bool post_dfs(TreeNode* root, long left, long right){
    if(!root)
        return true;

    int val = root->val;
    bool node_res = (left < val) && (val < right);

    return node_res && post_dfs(root->left, left, val) && post_dfs(root->right, val, right);
}

bool mid_dfs(TreeNode* root, long& pre){
    if(!root)
        return true;

    bool left_res = mid_dfs(root->left, pre);

    if(!left_res || root->val <= pre)
        return false;

    pre = root->val;
    bool right_res = mid_dfs(root->right, pre);

    return right_res;
}
bool isValidBST(TreeNode* root) {
    //return post_dfs(root, LONG_MIN, LONG_MAX);
    long pre = LONG_MIN;
    return mid_dfs(root, pre);
}

TreeNode* pre = nullptr;

bool isValidBST_(TreeNode* root) {
    if (!root)
        return true;

    bool res_left = isValidBST(root->left);

    if (pre && pre->val >= root->val)
        return false;

    pre = root;

    bool res_right = isValidBST(root->right);

    return res_left && res_right;
}
