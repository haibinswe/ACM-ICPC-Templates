for (int i = 0; i <= V; i++)
{
    for (int j = 0; j <= U; j++)
        dp[i][j] = 0;
}
for (int i = 1; i <= N; i++)
{
    for (int j = V; j >= v[i]; j--)
    {
        for (int k = U; k >= u[i]; k--)
            dp[j][k] = max(dp[j][k], dp[j - v[i]][k - u[i]] + w[i]);
    }
}
