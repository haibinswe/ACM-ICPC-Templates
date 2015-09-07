const long long M = 1000000007;
long long quickpow(long long A, long long n)
{
    if (n == 0) return 1;
    long long ret = 1;
    while (n)
    {
        if (n & 1) ret = (ret * A) % M;
        A = (A * A) % M;
        n >>= 1;
    }
    return ret;
}

long long inv(long long a)
{
    return quickpow(a, M - 2);
}
