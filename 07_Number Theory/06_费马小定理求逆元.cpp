const long long M = 1000000007;
long long qPow(long long A, long long n)
{
    if (n == 0) return 1;
    long long rslt = 1;
    while (n)
    {
        if (n & 1)  //如果n为奇数
        {
            rslt = (resl * A) % M;
        }
        A = (A * A) % M;
        n >>= 1;
    }
    return rslt;
}

long long inv(long long a)
{
    return qPow(a, M - 2);
}
