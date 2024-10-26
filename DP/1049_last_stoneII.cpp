#include "../headers.h" // IWYU pragma: keep

int lastStoneWeightII(vector<int>& stones) {
    int n = stones.size();
    int sum = accumulate(stones.begin(), stones.end(), 0);

    int target = sum / 2;

    vector dp(target + 1, 0);
    for (int i = 0; i < n; ++i) {
        int elem_val = stones[i];
        for (int j = target; j > 0; j--) {
            if (j >= elem_val)
                dp[j] = max(dp[j], dp[j - elem_val] + elem_val);
        }
    }

    return sum - dp[target] - dp[target];
}
