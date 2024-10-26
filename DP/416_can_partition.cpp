#include "../headers.h" // IWYU pragma: keep

bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);

    int target = sum / 2;
    if (sum % 2)
        return false;

    vector dp(target + 1, 0);
    for (int i = 0; i < n; ++i) {
        int elem_val = nums[i];
        for (int j = target; j > 0; j--) {
            if (j >= elem_val)
                dp[j] = max(dp[j], dp[j - elem_val] + elem_val);
            if (dp[target] == target)
                return true;
        }
    }

    return false;
}
