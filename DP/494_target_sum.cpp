#include "../headers.h" // IWYU pragma: keep

int findTargetSumWays(vector<int>& nums, int target) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (abs(target) > sum)
        return 0;

    int left = (target + sum) / 2;
    if ((target + sum) % 2 == 1)
        return 0;

    vector<int> dp(left+1);
    dp[0] = 1;

    for(uint i = 0; i < nums.size(); ++i){
        for(int j = left; j >= nums[i]; j--){
            dp[j] += dp[j-nums[i]];
        }
    }

    return dp[left];
}
