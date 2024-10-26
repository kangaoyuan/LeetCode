#include "../headers.h" // IWYU pragma: keep

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hash_map;
    for (int i = 0; i < (int)nums.size(); i++) {
        auto it = hash_map.find(target - nums[i]);
        if (it != hash_map.end()) {
            //return {i, it->second};
            return {it->second, i};
        }
        //hash_map[nums[i]] = i;
        hash_map.insert({nums[i], i});
    }
    return {};
}
