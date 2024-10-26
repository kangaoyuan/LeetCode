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


TreeNode* getPreNode(TreeNode* cur) {
    if (cur->left && cur->right) {
        TreeNode* parent = cur;
        TreeNode* child = cur->left;

        while (child->right) {
            parent = child;
            child = child->right;
        }

        // if(parent == cur){
        if (parent->val == cur->val) {
            parent->left = child->left;
        } else {
            parent->right = child->left;
        }

        child->left = cur->left;
        child->right = cur->right;

        cur = child;
    }
    else if (!cur->left && cur->right) {
        cur = cur->right;
    }
    else if (!cur->right && cur->left) {
        cur = cur->left;
    }
    else if (!cur->left && !cur->right) {
        cur = nullptr;
    }

    return cur;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    TreeNode* pre = NULL;
    TreeNode* cur = root;

    while (cur) {
        if (key < cur->val) {
            pre = cur;
            cur = cur->left;
        } else if (key == cur->val) {
            cur = getPreNode(cur);
            if(!pre)
                return cur;

            if (pre->left && pre->left->val == key)
                pre->left = cur;
            else
                pre->right = cur;

            break;
        } else {
            pre = cur;
            cur = cur->right;
        }
    }

    return root;
}

TreeNode* deleteNode_(TreeNode* root, int key) {
    if (!root)
        return nullptr;

    if (root->val == key) {
        TreeNode *pre = nullptr, *cur = root->left;
        if (cur) {
            while (cur->right) {
                pre = cur;
                cur = cur->right;
            }
            if (!pre) {
                cur->right = root->right;
            } else {
                pre->right = cur->left;
                cur->left = root->left;
                cur->right = root->right;
            }
            return cur;
        } else {
            return root->right;
        }
    }

    root->left = deleteNode_(root->left, key);
    root->right = deleteNode_(root->right, key);

    return root;
}
