#include "../headers.h"  // IWYU pragma: keep

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1])
        return 0;

    vector dp(n, 0);
    dp[0] = 1;
    for (int i = 1; i < n; i++){
        if(obstacleGrid[0][i])
            break;
            //dp[i] = 0;
        else
            dp[i] = dp[i-1];
    }

    for (int i = 1; i < m; i++) {
        if(obstacleGrid[i][0])
            dp[0] = 0;
        for (int j = 1; j < n; j++) {
            dp[j] = dp[j] + dp[j - 1];
            if(obstacleGrid[i][j])
                dp[j] = 0;
        }
    }

    return dp[n - 1];
}
