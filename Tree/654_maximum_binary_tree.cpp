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

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    if(nums.empty())
        return NULL;

    int index = -1, max = INT_MIN;

    for (uint i = 0; i < nums.size(); ++i) {
        if (nums[i] > max) {
            index = i;
            max = nums[i];
        }
    }

    TreeNode *node = new TreeNode(nums[index]);

    vector left_vec(nums.cbegin(), nums.cbegin()+index);
    vector right_vec(nums.cbegin()+index+1, nums.cend());

    node->left =  constructMaximumBinaryTree(left_vec);
    node->right = constructMaximumBinaryTree(right_vec);

    return node;
}
