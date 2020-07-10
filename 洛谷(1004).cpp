#include <cstdio>
#include <algorithm>

using namespace std;

int max_num(int a, int b, int c, int d) {
    return max(max(a, b), max(c, d));
}

int main() {
    int n = 0;
    int map[10][10] = {0};
    int dp[10][10][10][10] = {0};
    scanf("%d", &n);
    for (int i = 0;; i++) {
        int x, y, value = 0;
        scanf("%d%d%d", &x, &y, &value);
        if (x == 0 && y == 0 && value == 0)
            break;
        else
            map[x][y] = value;
    }
    dp[1][1][1][1] = map[1][1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                for (int l = 1; l <= n; l++) {
                    dp[i][j][k][l] = max_num(dp[i][j - 1][k][l - 1], dp[i - 1][j][k - 1][l],
                                             dp[i][j - 1][k - 1][l], dp[i - 1][j][k][l - 1]) + map[i][j];
                    if (!(i == k && j == l))
                        dp[i][j][k][l] += map[k][l];
                }

    printf("%d", dp[n][n][n][n]);
    return 0;
}
