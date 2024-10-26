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

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(!root){
        return new TreeNode(val);
    }

    if(root->val < val)
        root->right = insertIntoBST(root->right, val);
    else
        root->left = insertIntoBST(root->left, val);

    return root;
}

TreeNode* insertIntoBST_(TreeNode* root, int val) {
    if(!root){
        TreeNode* node = new TreeNode(val);
        return node;
    }

    TreeNode* cur = root;

    while(true){
        if(cur->val < val) {
            if(cur->right)
                cur = cur->right;
            else{
                TreeNode* node = new TreeNode(val);
                cur->right = node;
                break;
            }
        }
        else if(cur->val > val) {
            if(cur->left)
                cur = cur->left;
            else{
                TreeNode* node = new TreeNode(val);
                cur->left = node;
                break;
            }
        }
    }

    return root;
}
