#include "../headers.h" // IWYU pragma: keep

vector<int>         path;
vector<vector<int>> res;

void backtrace(vector<int>& nums, uint start_index) {
    if (path.size() > 1)
        res.push_back(path);
    if (start_index == nums.size())
        return;

    for (uint i = start_index; i < nums.size(); ++i) {
        if (!path.empty() && nums[i] < path.back())
            continue;

        path.push_back(nums[i]);
        backtrace(nums, i + 1);
        path.pop_back();
    }
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
    backtrace(nums, 0);
    set<vector<int>>    sorted(res.begin(), res.end());
    vector<vector<int>> res_(sorted.begin(), sorted.end());
    return res_;
    return res_;
}
