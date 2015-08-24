int a[100005];
int dp[100005] = {};
for (int i = 1; i <= n; i++)
{
    dp[i] = max(a[i], dp[i - 1] + a[i]);
}

for (int i = 2; i <= n; i++)
{
    dp[i] = max(dp[i - 1], dp[i]);
}

//输出子段起始点
while(scanf("%d", &n), n)
{
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        if (dp[i - 1] < 0)
        {
            b[i] = i;
            dp[i] = a[i];
        }
        else
        {
            b[i] = b[i - 1];
            dp[i] = dp[i - 1] + a[i];
        }
    }
    int index, mx = -1;
    for (int i = 1; i <= n; i++)
        if (dp[i] > mx)
        {
            mx = dp[i];
            index = i;
        }
    if (mx < 0)
    {
        printf("%d %d %d\n", 0, a[1], a[n]);
    }
    else
    {
        printf("%d %d %d\n", mx, a[b[index]], a[index]);
    }
}

//单纯计算最大子段和
int a[100005];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    ll sum = 0, maxi = -inf;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum < 0) sum = 0;
        if (sum > maxi)
            maxi = sum;
    }
    printf("%I64d\n", maxi);
    return 0;
}
