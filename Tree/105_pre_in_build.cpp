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

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if(!preorder.size())
        return nullptr;

    int root_val = preorder[0], index = 0;

    for(uint i = 0; i < inorder.size(); ++i){
        if(inorder[i] == root_val){
            index = i;
            break;
        }
    }

    TreeNode* root = new TreeNode(root_val);

    vector<int> preorder_left(preorder.begin()+1, preorder.begin()+1+index);
    vector<int> preorder_right(preorder.begin()+1+index, preorder.end());
    vector<int> inorder_left(inorder.begin(), inorder.begin()+index);
    vector<int> inorder_right(inorder.begin()+index+1, inorder.end());
    root->left = buildTree(preorder_left, inorder_left);
    root->right = buildTree(preorder_right, inorder_right);


    return root;
}
