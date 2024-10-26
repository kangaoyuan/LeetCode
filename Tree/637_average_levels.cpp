#include <sys/types.h>
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

vector<double> averageOfLevels(TreeNode* root) {
    vector<double> res;
    queue<TreeNode*> que;

    if(root)
        que.push(root);

    while(!que.empty()){
        double level_sums = 0;
        int level_nums = que.size();

        for(int i = 0; i < level_nums; ++i) {
            auto node = que.front();
            que.pop();

            level_sums += node->val;

            if(node->left)
                que.push(node->left);
            if(node->right)
                que.push(node->right);
        }

        double average = level_sums / level_nums;
        res.push_back(average);
    }

    return res;
}
