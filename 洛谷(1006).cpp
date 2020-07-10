#include <cstdio>
#include <algorithm>

#define MY_INF -2100000000
using namespace std;

int max_num(int a, int b, int c, int d) {
    return max(max(a, b), max(c, d));
}


int map[51][51] = {0};
int dp[51][51][51][51] = {0};

int main() {
    int m, n = 0;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &map[i][j]);

    dp[1][1][1][1] = map[1][1];
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= m; k++)
                for (int l = 1; l <= n; l++) {
                    if (i == 1 && k == 1 && j == 1 && l == 1)
                        continue;
                    if (i == m && k == m && j == n && l == n) {
                        dp[i][j][k][l] = max_num(dp[i][j - 1][k][l - 1],
                                                 dp[i - 1][j][k - 1][l],
                                                 dp[i][j - 1][k - 1][l],
                                                 dp[i - 1][j][k][l - 1]);
                        continue;
                    }
                    if (i == k && j == l)
                        dp[i][j][k][l] = MY_INF;
                    else
                        dp[i][j][k][l] = max_num(dp[i][j - 1][k][l - 1],
                                                 dp[i - 1][j][k - 1][l],
                                                 dp[i][j - 1][k - 1][l],
                                                 dp[i - 1][j][k][l - 1]) + map[i][j] + map[k][l];
                }

    printf("%d", dp[m][n][m][n]);
    return 0;
}
