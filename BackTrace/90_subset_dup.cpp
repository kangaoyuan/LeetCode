#include "../headers.h" // IWYU pragma: keep

vector<int> path;
vector<vector<int>> res;

void bt(vector<int>& nums, uint start_index){
    res.push_back(path);

    if(nums.size() == start_index){
        return;
    }

    for(uint i = start_index; i < nums.size(); ++i){
        path.push_back(nums[i]);
        bt(nums, i+1);
        path.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    bt(nums, 0);
    return res;
}
