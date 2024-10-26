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

unordered_map<int, int> rec;

void iterate_tree(TreeNode* root){
    if(!root)
        return;
    rec[root->val]++;
    iterate_tree(root->left);
    iterate_tree(root->right);
}

vector<int> findMode(TreeNode* root) {
    iterate_tree(root);

    //vector<pair<int, int>> vec_(rec.begin(), rec.end());
    vector<pair<int, int>> vec;
    for (const auto& elem : rec) {
        vec.push_back(elem);
    }

    auto cmp = [](pair<int, int> p1, pair<int, int> p2) {
        return p1.second > p2.second;
    };

    sort(vec.begin(), vec.end(), cmp);

    vector<int> res;

    res.push_back(vec[0].first);
    for (uint i = 1; i < vec.size(); ++i) {
        if (vec[i].second == vec[0].second)
            res.push_back(vec[i].first);
        else
            break;
    }

    return res;
}

TreeNode* pre = nullptr;
int       cnt = 0, res_cnt = 0;

void search_BST(TreeNode* root, vector<int>& res) {
    if (!root)
        return;

    search_BST(root->left, res);

    if (!pre || pre->val == root->val) {
        cnt++;
    } else {
        cnt = 1;
    }
    pre = root;

    if (cnt > res_cnt) {
        res_cnt = cnt;
        res.clear();
        res.push_back(root->val);
    } else if (cnt == res_cnt) {
        res.push_back(root->val);
    }

    search_BST(root->right, res);
}

vector<int> findMode_(TreeNode* root) {
    vector<int> res;
    search_BST(root, res);
    return res;
}
