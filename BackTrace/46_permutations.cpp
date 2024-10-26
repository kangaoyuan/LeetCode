#include "../headers.h" // IWYU pragma: keep

vector<int> path, used;
vector<vector<int>> res;

void backtrace(const vector<int>& nums){
    if(path.size() == nums.size()){
        res.push_back(path);
        return;
    }

    for(uint i = 0; i < nums.size(); ++i){
        if(used[i] == true)
            continue;

        used[i] = true;
        path.push_back(nums[i]);
        backtrace(nums);
        path.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    used.resize(nums.size());
    backtrace(nums);
    return res;
}
