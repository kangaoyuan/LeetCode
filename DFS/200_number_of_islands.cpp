#include "../headers.h" // IWYU pragma: keep

uint64_t dfs(vector<vector<char>>& grid, int i, int j) {
    if (i < 0 || j < 0 || i == (int)grid.size() ||
        j == (int)grid[0].size() || grid[i][j] == '0')
        return 0;

    grid[i][j] = '0';
    int x[4] = {0, 0, 1, -1};
    int y[4] = {1, -1, 0, 0};

    for (int d = 0; d < 4; d++) {
        int next_i = i + x[d];
        int next_j = j + y[d];
        dfs(grid, next_i, next_j);
    }

    return 1;
}

int numIslands(vector<vector<char>>& grid) {
    uint64_t res = 0;

    for (uint i = 0; i < grid.size(); ++i) {
        for (uint j = 0; j < grid[0].size(); ++j) {
            res += dfs(grid, i, j);
        }
    }

    return res;
}
