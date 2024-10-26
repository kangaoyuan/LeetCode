#include "../headers.h"  // IWYU pragma: keep

vector<int> path;
vector<vector<int>> res;

void backtrace_(uint k, int target, int sums, int first) {
    if(sums > target)
        return;

    if (path.size() == k) {
        if (sums == target)
            res.push_back(path);
        return;
    }

    for (uint i = first; i <= 9 - (k - path.size()) + 1; ++i) {
        sums += i;
        path.push_back(i);
        backtrace_(k, target, sums, i+1);
        path.pop_back();
        sums -= i;
    }
}

vector<vector<int>> combinationSum3_(int k, int n) {
    backtrace_(k, n, 0, 1);
    return res;
}



void backtrace(uint nums, int target, int first) {
    if (target < 0)
        return;

    if (path.size() == nums) {
        if (target == 0) {
            res.push_back(path);
        }
        return;
    }

    for (uint i = first; i <= 9 - (nums - path.size()) + 1; ++i) {
        path.push_back(i);
        backtrace(nums, target - i, i + 1);
        path.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    backtrace(k, n, 1);
    return res;
}
