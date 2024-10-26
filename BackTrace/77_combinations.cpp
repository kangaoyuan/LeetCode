#include "../headers.h" // IWYU pragma: keep

vector<int> path;
vector<vector<int>> res;

void backtrace(int n, int k, int first){
    if((int)path.size() == k){
        res.push_back(path);
        return;
    }

    [[maybe_unused]]int remain_path = k - path.size();
    for (uint i = first; i <= n - (k - path.size()) + 1; ++i) {
        path.push_back(i);
        backtrace(n, k, i+1);
        path.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    backtrace(n, k, 1);
    return res;
}

void backtrace_(int n, int k, int start_idx){
        if(k == 0){
            res.push_back(path);
            return;
        }

        for (int i = start_idx; i <= n - k + 1; ++i) {
            path.push_back(i);
            backtrace(n, k - 1, i + 1);
            path.pop_back();
        }
}

vector<vector<int>> combine_(int n, int k) {
    backtrace(n, k, 1);
    return res;
}
