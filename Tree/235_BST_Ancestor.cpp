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


TreeNode* lowestCommonAncestor_(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root)
        return NULL;

    if(p->val < root->val && q->val < root->val){
        return lowestCommonAncestor_(root->left, p, q);
    }

    if(p->val > root->val && q->val > root->val){
        return lowestCommonAncestor_(root->right, p, q);
    }

    return root;
}

bool find_node(TreeNode* root, TreeNode* node){
        if(!root)
            return false;

        if(root->val < node->val){
            return find_node(root->right, node);
        } else if (root->val == node->val){
            return true;
        } else{
            return find_node(root->left, node);
        }
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root)
        return nullptr;
    if (p->val > q->val)
        swap(p, q);
    if (root->val == p->val || root->val == q->val)
        return root;

    bool res_left = find_node(root->left, p);
    bool res_right = find_node(root->right, q);

    //while (!res_left || !res_right) {
        if (!res_left)
            return lowestCommonAncestor(root->right, p, q);
        else if (!res_right)
            return lowestCommonAncestor(root->left, p, q);
    //}

    return root;
}
