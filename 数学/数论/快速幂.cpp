long long quickpow(long long A, long long n, long long m)
{
    if (n == 0) return 1;
    long long ret = 1;
    while (n)
    {
        if (n & 1) ret = (ret * A) % m;
        A = (A * A) % m;
        n >>= 1;
    }
    return ret;
}
