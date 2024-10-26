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

//vector<int> res;
void in_dfs(TreeNode* root, vector<int>& res){
    if(!root)
        return;
    in_dfs(root->left, res);
    res.push_back(root->val);
    in_dfs(root->right, res);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    in_dfs(root, res);
    return res;
}

vector<int> inorderTraversal_(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;

    TreeNode* cur = root;
    while(cur || !st.empty()){
        if(cur){
            st.push(cur);
            cur = cur->left;
        } else {
            auto node = st.top();
            st.pop();
            res.push_back(node->val);
            cur = node->right;
        }
    }

    return res;
}
