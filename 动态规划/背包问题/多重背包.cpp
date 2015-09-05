for (int i = 1; i <= N; i++)
{
    if (v[i] * a[i] > V) //如果物品够多，问题实际上就是完全背包问题
    {
        for (int j = v[i]; j <= V; j++)
        {
            if (j >= v[i]) dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    else
    {
        int k = 1, amount = a[i];
        while (k < amount)
        {
            //是否取一个重量为k*v[i], 价值为k*w[i]的物品
            for (int j = k * v[i]; j >= 0; j--)
            {
                dp[j] = max(dp[j], dp[j - v[i]] + k * w[i]);
            }
            amount -= k;
            k += k;
        }
        //把剩下的作为单独一个物品
        for (int j = amount * v[i]; j >= 0; j--)
        {
            dp[j] = max(dp[j], dp[j - v[i]] + amount * w[i]);
        }
    }
}
