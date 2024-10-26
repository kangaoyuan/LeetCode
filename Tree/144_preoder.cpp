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
void pre_dfs(TreeNode* root, vector<int>& res){
    if(!root)
        return;
    res.push_back(root->val);
    pre_dfs(root->left, res);
    pre_dfs(root->right, res);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    pre_dfs(root, res);
    return res;
}

vector<int> preorderTraversal_(TreeNode* root) {
    if(!root)
        return {};
    vector<int> res;
    stack<TreeNode*> st;

    st.push(root);
    while(!st.empty()){
        TreeNode* node = st.top();
        st.pop();

        res.push_back(node->val);

        if(node->right)
            st.push(node->right);
        if(node->left)
            st.push(node->left);
    }

    return res;
}
