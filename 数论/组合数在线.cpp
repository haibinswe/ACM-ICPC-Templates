const int fcnt = 100005;
const long long M = 1000000007;
long long fac[fcnt];
long long qPow(long long A, long long n)
{
    if (n == 0) return 1;
    long long rslt = 1;
    while (n)
    {
        if (n & 1) rslt = (rslt * A) % M;
        A = (A * A) % M;
        n >>= 1;
    }
    return rslt;
}

long long inv(long long a)
{
    return qPow(a, M - 2);
}

void getfac()
{
    fac[0] = 1;
    for (int i = 1; i < fcnt; i++)
    {
        fac[i] = fac[i - 1] * i % M;
    }
}

long long C(long long n, long long m)
{
    if (n < m) return 0;
    return fac[n] * inv(fac[m]) % M * inv(fac[n - m]) % M;
}

int main()
{
    getfac();

    return 0;
}
