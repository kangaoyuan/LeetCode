#include "../headers.h"  // IWYU pragma: keep

int uniquePaths(int m, int n) {
    vector dp(n, 0);
    for (int i = 0; i < n; i++)
        dp[i] = 1;

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            dp[j] = dp[j] + dp[j - 1];

    return dp[n - 1];
}

/*
 *int uniquePaths(int m, int n) {
 *    vector<vector<int>> dp(m, vector<int>(n));
 *
 *    for (int i = 0; i < m; ++i)
 *        dp[i][0] = 1;
 *    for (int i = 0; i < n; ++i)
 *        dp[0][i] = 1;
 *
 *    for (int i = 1; i < m; ++i) {
 *        for (int j = 1; j < n; ++j) {
 *            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
 *        }
 *    }
 *
 *    return dp[m - 1][n - 1];
 *}
 */