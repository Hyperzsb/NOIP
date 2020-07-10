#include <cstdio>

int main() {
    int pearl_num = 0;
    scanf("%d", &pearl_num);
    int *flag_list = new int[pearl_num];
    int *tmp_list = new int[pearl_num];
    int **dp = new int *[pearl_num];
    for (int i = 0; i < pearl_num; i++) {
        dp[i] = new int[pearl_num];
        dp[i][i] = 0;
    }
    int ans = 0;
    for (int i = 0; i < pearl_num; i++)
        scanf("%d", flag_list + i);
    for (int i = 0; i < pearl_num; i++) {
        for (int j = 0; j < pearl_num; j++)
            tmp_list[j] = flag_list[(j + i) % pearl_num];
        for (int step = 1; step <= pearl_num - 1; step++)
            for (int start = 0; start < pearl_num - step; start++) {
                int end = start + step;
                dp[start][end] = 0;
                for (int divide = start; divide < end; divide++) {
                    int tmp = dp[start][divide] + dp[divide + 1][end] +
                              tmp_list[start] * tmp_list[divide + 1] * tmp_list[(end + 1) % pearl_num];
                    if (tmp > dp[start][end])
                        dp[start][end] = tmp;
                }
            }
        if (dp[0][pearl_num - 1] > ans)
            ans = dp[0][pearl_num - 1];
    }
    printf("%d", ans);
    return 0;
}
