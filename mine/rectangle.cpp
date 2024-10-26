#include "../headers.h" // IWYU pragma: keep

vector<vector<int>> generateMatrix(int n) {
    int                 cnt = 1, side = 1;
    vector<vector<int>> res(n, vector<int>(n));

    for (int loop = 0; loop < n / 2; loop++, side++) {
        for (int j = loop; j < n - side; j++)
            res[loop][j] = cnt++;
        for (int i = loop; i < n - side; i++)
            res[i][n - side] = cnt++;
        for (int j = n - side; j > loop; j--)
            res[n - side][j] = cnt++;
        for (int i = n - side; i > loop; i--)
            res[i][loop] = cnt++;
    }

    if (n % 2)
        res[n / 2][n / 2] = cnt;

    return res;
}
