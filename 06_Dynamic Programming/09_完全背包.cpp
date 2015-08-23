const int MAXN = 10005;
//worth    volume
int dp[MAXN], w[MAXN], v[MAXN];

int N, V;
for (int i = 1; i <= N; i++)
{
	for (int j = v[i]; j <= V; j++)
	{
		dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
	}
}
printf("%d\n", dp[V]);