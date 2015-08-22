int qPow(int A, int n)
{
    if (n == 0) return 1;
    int rslt = 1;
    while (n)
    {
        if (n & 1) //如果n为奇数
        {
            rslt = resl * A;
        }
        A = A * A;
        n >>= 1;
    }
    return rslt;
}
