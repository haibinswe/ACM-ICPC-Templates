//HDU 1712
int a[105][105], dp[105];
int main()
{
    int N, M;
    while (~scanf("%d%d", &N, &M) && N)
    {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
                scanf("%d", &a[i][j]);
        }
        for (int i = 1; i <= N; i++)
        {
            for (int j = M; j >= 0; j--)
            {
                for (int k = 1; k <= j; k++)
                    dp[j] = max(dp[j], dp[j - k] + a[i][k]);
            }
        }
        printf("%d\n", dp[M]);
    }
    return 0;
}

//HDU 3535
for (int i = 1; i <= N; i++)
{
    //每组里面M个物品
    for (int k = 1; k <= M; k++)
    {
        for (int j = t; j >= v[k]; j--)
        {
            if (dp[i][j - v[k]] != -1)
                dp[i][j] = max(dp[i][j], dp[i][j - v[k]] + w[k]);
            if (dp[i - 1][j - v[k]] != -1)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[k]] + w[k]);
        }
    }
}
