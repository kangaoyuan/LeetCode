#include "../headers.h"  // IWYU pragma: keep

struct TreeNode {
    int       val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int node_nums = inorder.size();
    if (!node_nums)
        return nullptr;

    int root_val = postorder[node_nums - 1], index = 0;

    for (uint i = 0; i < inorder.size(); ++i) {
        if (inorder[i] == root_val) {
            index = i;
            break;
        }
    }

    TreeNode* root = new TreeNode(root_val);

    vector<int> inorder_left(inorder.begin(), inorder.begin() + index);
    vector<int> inorder_right(inorder.begin() + index + 1, inorder.end());

    vector<int> postorder_left(postorder.begin(),
                               postorder.begin() + index);
    vector<int> postorder_right(postorder.begin() + index,
                                postorder.end() - 1);

    root->left = buildTree(inorder_left, postorder_left);
    root->right = buildTree(inorder_right, postorder_right);

    return root;
}
