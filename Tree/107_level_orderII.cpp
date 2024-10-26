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

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if(!root)
        return {};

    queue<TreeNode*> que;
    // or using vector<vector<int>> obj and then reverse it.
    stack<vector<int>> res;

    que.push(root);
    while(!que.empty()){
        vector<int> level_node;
        // This step is the core and maybe a pitfall.
        int level_num = que.size();
        for (int i = 0; i < level_num; ++i) {
            TreeNode* node = que.front();
            que.pop();

            level_node.push_back(node->val);
            if (node->left) {
                que.push(node->left);
            }
            if (node->right) {
                que.push(node->right);
            }
        }
        assert((uint)level_num == level_node.size());
        res.push(level_node);
    }

    vector<vector<int>> ans;
    while(!res.empty()){
        ans.push_back(res.top());
        res.pop();
    }

    return ans;
}
