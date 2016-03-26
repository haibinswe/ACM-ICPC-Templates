const int N = 1005;
int sum[N], isprime[N], prime[N], mu[N], pcnt;
void GetMobius()
{
    pcnt = 0;
    memset(isprime, 0, sizeof(isprime));
    mu[1] = 1;
    for (int i = 2; i < N; i++)
    {
        if (!isprime[i])
        {
            prime[pcnt++] = i;
            mu[i] = -1;
        }
        for (int j = 0; j < pcnt && i * prime[j] < N; j++)
        {
            isprime[i * prime[j]] = 1;
            if (i % prime[j]) mu[i * prime[j]] = -mu[i];
            else
            {
                mu[i * prime[j]] = 0;
                break;
            }
        }
    }
    for (int i = 1; i < N; i++)
        sum[i] = sum[i - 1] + mu[i];
}
//求1 <= x <= n,1 <= y <= m中 gcd(x,y) == 1的个数
long long solve(int n, int m)
{
    long long res = 0;
    if (n > m) swap(n, m);
    for (int i = 1, last = 0; i <= n; i = last + 1)
    {
        last = min(n / (n / i), m / (m / i));
        res += (long long)(n / i) * (m / i) * (sum[last] - sum[i - 1]);
    }
    return res;
}
