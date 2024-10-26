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

int min_depth = INT_MAX;
void dfs(TreeNode* root, int depth){
    if(!root)
        return;
    if(!root->left && !root->right){
        min_depth = min(min_depth, depth);
        return;
    }
    dfs(root->left, depth+1);
    dfs(root->right, depth+1);
}

int minDepth(TreeNode* root) {
    if(!root)
        return 0;

    dfs(root, 1);
    return min_depth;
}

// Here we use the pruning to optimize.
void dfs(TreeNode* root, int depth, int& min_depth){
    if(!root || depth >= min_depth)
        return;
    if(!root->left && !root->right){
        min_depth = min(min_depth, depth);
        return;
    }
    dfs(root->left, depth+1, min_depth);
    dfs(root->right, depth+1, min_depth);
}

// global vairables can pass by pointers or reference
int minDepth_(TreeNode* root) {
    if(!root)
        return 0;

    int min_depth = INT_MAX;
    dfs(root, 1, min_depth);
    return min_depth;
}

// From bottom to top
int minDepth__(TreeNode* root) {
    if (!root)
        return 0;

    // better to eliminate extra evaluations.
    /*
     *if (root->right == nullptr) {
     *    return minDepth(root->left) + 1;
     *}
     *if (root->left == nullptr) {
     *    return minDepth(root->right) + 1;
     *}
     */

    int depth_left = minDepth(root->left);
    int depth_right = minDepth(root->right);

    if (depth_left == 0 || depth_right == 0)
        return 1 + max(depth_left, depth_right);

    return 1 + min(depth_left, depth_right);
}

int minDepth___(TreeNode* root) {
    if(!root)
        return 0;

    queue<TreeNode*> que;
    que.push(root);

    int min_depth = 0;
    while(!que.empty()) {
        min_depth++;
        int level_nums = que.size();
        for(int i = 0; i < level_nums; ++i){
            auto node = que.front();
            que.pop();
            if(!node->left && !node->right)
                return min_depth;
            if(node->left)
                que.push(node->left);
            if(node->right)
                que.push(node->right);
        }
    }

    return min_depth;
}
