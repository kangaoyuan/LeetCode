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

vector<int> path;

bool hasPathSum(TreeNode* root, int targetSum) {
    if(!root)
        return false;

    if(!root->left && !root->right){
        int sum = accumulate(path.begin(), path.end(), 0);
        if(sum + root->val == targetSum)
            return true;
        return false;
    }

    path.push_back(root->val);
    if(hasPathSum(root->left, targetSum))
        return true;
    path.pop_back();

    path.push_back(root->val);
    if(hasPathSum(root->right, targetSum))
        return true;
    path.pop_back();

    return false;
}
