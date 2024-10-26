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

int countNodes(TreeNode* root) {
    if(!root)
        return 0;

    int count_left = countNodes(root->left);
    int count_right = countNodes(root->right);

    if(count_left == count_right)
        return (count_left << 1) + 1;
    else
        return count_left + count_right + 1;
}

int countNodes_(TreeNode* root) {
    if(!root)
        return 0;

    int height_left = 0;
    int height_right = 0;

    for(auto left = root->left; left; left = left->left){
        height_left++;
    }

    for(auto right = root->right; right; right = right->right){
        height_right++;
    }

    if(height_left == height_right)
        return (2 << height_left) - 1;
    else
        return countNodes_(root->left) + countNodes_(root->right) + 1;
}
