//输出子段起始点
int dp[1000], flag[1000];
int L, R;
int Sum(int *a, int n)
{
    L = R = 0;
    dp[0] = a[0];
    flag[0] = false;
    int ans = a[0];
    for (int i = 1; i < n; i++)
    {
        if (dp[i - 1] < 0)
        {
            flag[i] = false;
            dp[i] = a[i];
        }
        else
        {
            flag[i] = true;
            dp[i] = dp[i - 1] + a[i];
        }
        if (ans < dp[i])
        {
            ans = dp[i];
            R = i;
        }
    }
    for (int i = R; i >= 0; i--)
    {
        if (!flag[i])
        {
            L = i;
            break;
        }
    }
    L++, R++;
    return ans;
}

//简单计算
int Sum(int *a, int n)
{
    int sum = 0, maxn = -inf;
    for (int i = 0; i < n; i++)
    {
        if (sum + a[i] < 0) sum = 0;
        else maxn = max(maxn, sum += a[i]);
    }
    return maxn;
}
