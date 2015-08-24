//UVa 10692
long long phi(long long n)
{
    long long ans = n;
    long long x = sqrt(n);
    for (long long i = 2; i <= x; i++)
    {
        if (n % i == 0)
        {
            while(n % i == 0)
            {
                n /= i;
            }
            ans = ans / i * (i - 1);
        }
    }
    if (n > 1)
    {
        ans = ans / n * (n - 1);
    }
    return ans;
}

long long qPow(long long A, long long n, long long c)
{
    if (n == 0) return 1;
    long long rslt = 1;
    while (n)
    {
        if (n & 1) rslt = (rslt * A) % c;
        A = (A * A) % c;
        n >>= 1;
    }
    return rslt;
}

long long solve(long long a[], int i, int n, long long c)
{
    if (i == n)
    {
        return a[i] % c;
    }
    long long p = phi(c);
    return qPow(a[i], solve(a, i + 1, n, p) % p + p, c);
}

int main()
{
    int m, n;
    int cas = 0;
    while (~scanf("%d%d", &m, &n))
    {
        long long a[50];
        for (int i = 1; i <= n; i++)
        {
            scanf("%I64d", &a[i]);
        }
        printf("Case #%d: %I64d\n", ++cas, solve(a, 1, n, m));
    }
    return 0;
}
