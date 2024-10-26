#include "../headers.h" // IWYU pragma: keep

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    for (int i = 0; i <= (int)nums.size() - 4; ++i) {
        if (i > 0 && nums[i - 1] == nums[i])
            continue;
        for (int j = i + 1; j <= (int)nums.size() - 3; ++j) {
            if (j > i + 1 && nums[j - 1] == nums[j])
                continue;

            int left = j + 1, right = nums.size() - 1;

            long two_target = (long)target - nums[i] - nums[j];
            while (left < right) {
                if (nums[left] + nums[right] < two_target)
                    left++;
                else if (nums[left] + nums[right] == two_target) {
                    res.push_back(
                        {nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left - 1] == nums[left])
                        left++;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                } else {
                    right--;
                }
            }
        }
    }

    return res;
}
