#include "../headers.h" // IWYU pragma: keep

vector<int> path, used;
vector<vector<int>> res;

void backtrace(const vector<int>& nums){
    if(path.size() == nums.size()){
        res.push_back(path);
        return;
    }


    for(uint i = 0; i < nums.size(); ++i){
        if(i > 0 && used[i-1] == false && nums[i-1] == nums[i])
            continue;
        if(used[i] == true)
            continue;

        used[i] = true;
        path.push_back(nums[i]);
        backtrace(nums);
        path.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    used.resize(nums.size());
    sort(nums.begin(), nums.end());
    backtrace(nums);
    return res;
}

