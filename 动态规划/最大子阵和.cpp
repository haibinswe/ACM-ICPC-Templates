int t[500][500], dp[500][500];
int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                scanf("%d", &t[i][j]);
        }
        memset(dp, 0, sizeof(dp));
        int maxn = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                dp[i][j] += t[i][j] + dp[i - 1][j];
            for (int j = 1; j <= i; j++)
            {
                int sum = 0;
                for (int k = 1; k <= n; k++)
                {
                    if (sum < 0) sum = dp[i][k] - dp[j - 1][k];
                    else sum += dp[i][k] - dp[j - 1][k];
                    maxn = max(maxn, sum);
                }
            }
        }
        printf("%d\n", maxn);
    }
    return 0;
}
