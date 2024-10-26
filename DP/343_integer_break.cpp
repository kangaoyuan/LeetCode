#include "../headers.h" // IWYU pragma: keep

int integerBreak(int n) {
    vector dp(n+1, 0);
    dp[2] = 1;

    for(int i = 3; i <= n; ++n) {
        for(int j = 1; j <= i/2; j++){
            dp[i] = max(dp[i], max(j * (i - j), j * dp[i -j]));
        }
    }

    return dp[n];
}

