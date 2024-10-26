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

uint depth = 0;
vector<int> rec;

int findBottomLeftValue(TreeNode* root) {
    if(!root)
        return 0;

    if(rec.size() == depth)
        rec.push_back(root->val);

    depth++;
    findBottomLeftValue(root->left);
    depth--;

    depth++;
    findBottomLeftValue(root->right);
    depth--;

    return rec[depth];
}
