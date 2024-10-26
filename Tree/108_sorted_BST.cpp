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

TreeNode* sortedArrayToBST(vector<int>& nums) {
    if(!nums.size())
        return NULL;

    int size = nums.size();
    TreeNode* root = new TreeNode(nums[size/2]);

    vector vec_left(nums.begin(), nums.begin() + size / 2);
    root->left = sortedArrayToBST(vec_left);

    vector vec_right(nums.begin() + size/2 + 1, nums.end());
    root->right = sortedArrayToBST(vec_right);

    return root;
}
