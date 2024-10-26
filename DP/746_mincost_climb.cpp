#include "../headers.h" // IWYU pragma: keep

int minCostClimbingStairs(vector<int>& cost) {
    size_t n = cost.size();

    vector dp(n+1, INT_MAX);
    dp[0] = 0;
    dp[1] = 0;
    for(uint i = 2; i <= n; ++i){
        dp[i] = min(dp[i-2]+cost[i-2], dp[i-1]+cost[i-1]);
    }

    return dp[n];
}
