#include "../headers.h" // IWYU pragma: keep

vector<vector<int>> threeSum(vector<int>& nums) {
    if(nums.size() < 3)
        return {};

    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    for(uint i = 0; i < nums.size()-2; ++i){
        if(nums[i] > 0)
            break;
        if (i > 0 && nums[i-1] == nums[i])
                continue;
        int target = 0 - nums[i];

        if(nums[i+1]+nums[i+2] > target)
            continue;
        if (nums[nums.size() - 1] + nums[nums.size() - 2] < target)
            continue;

        // This is [] interval
        uint left = i+1, right = nums.size()-1;
        // Here, we must keep two element to calculate.
        while(left < right){
            if (nums[left] + nums[right] == target){
                res.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right - 1] == nums[right])
                    right--;

                left++;
                right--;
            } else if (nums[left] + nums[right] < target) {
                left++;
            } else {
                right--;
            }
        }
    }

    return res;
}
