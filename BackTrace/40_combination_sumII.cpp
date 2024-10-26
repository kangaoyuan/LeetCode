#include "../headers.h" // IWYU pragma: keep

void backtrace(vector<int>& candidates, int target, uint start_index,
               vector<int>& path, vector<vector<int>>& res) {
    if (target < 0)
        return;

    if (target == 0) {
        res.push_back(path);
        return;
    }

    for (uint i = start_index; i < candidates.size(); i++) {
        if(i > start_index && candidates[i-1] == candidates[i])
            continue;
        int val = candidates[i];
        if(target-val < 0)
             return;

        path.push_back(val);
        // Here i representing the repeat action, i+1 representing not.
        backtrace(candidates, target - val, i+1, path, res);
        path.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int>         path;
    vector<vector<int>> res;
    sort(candidates.begin(), candidates.end());

    backtrace(candidates, target, 0, path, res);

    return res;
}
