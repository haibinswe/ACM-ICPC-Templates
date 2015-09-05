int m, n, ai, aj;
int a[505], b[505];
int dp[505][505];
int path[505][505];
int ans;
void LCIS()
{
    memset(dp, 0, sizeof(dp));
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int maxn = 0, t;
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = dp[i - 1][j];
            path[i][j] = -1;
            if (a[i] > b[j] && maxn < dp[i - 1][j])
            {
                maxn = dp[i - 1][j];
                t = j;
            }
            if (a[i] == b[j])
            {
                dp[i][j] = maxn + 1;
                path[i][j] = t;
            }
            if (ans < dp[i][j])
            {
                ans = dp[i][j];
                ai = i;
                aj = j;
            }
        }
    }
}

int p[505];
void getPath()
{
    int num = ans;
    while (num)
    {
        if (path[ai][aj] != -1)
        {
            p[num--] = b[aj];
            aj = path[ai][aj];
        }
        ai--;
    }
    printf("%d", p[1]);
    for (int i = 2; i <= ans; i++)
    {
        printf(" %d", p[i]);
    }
    printf("\n");
}
