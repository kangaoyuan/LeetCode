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
void post_dfs(TreeNode* root, vector<int>& res){
    if(!root)
        return;
    post_dfs(root->left, res);
    post_dfs(root->right, res);
    res.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    post_dfs(root, res);
    return res;
}

vector<int> postorderTraversal_(TreeNode* root) {
    if(!root)
        return {};

    vector<int> res;
    stack<TreeNode*> st;

    st.push(root);
    while(!st.empty()){
        auto node = st.top();
        st.pop();
        res.push_back(node->val);
        if(node->left)
            st.push(node->left);
        if(node->right)
            st.push(node->right);
    }

    reverse(res.begin(), res.end());

    return res;
}
