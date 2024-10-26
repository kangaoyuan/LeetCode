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

void dfs(TreeNode* root, string path, vector<string>& res){
    if(!root){
        return;
    }

    if(!root->left && !root->right){
        path += to_string(root->val);
        res.push_back(path);
        return;
    }

    path += to_string(root->val);
    path += "->";

    dfs(root->left, path, res);
    dfs(root->right, path, res);
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    dfs(root, "", res);
    return res;
}
