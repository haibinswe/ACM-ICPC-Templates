//判断自然数 n 是否为素数
//times 越高失败概率越低
int mod_pro(int x, int y, int n)
{
    int ret = 0, tmp = x % n;
    while (y)
    {
        if (y & 0x1)
        {
            if ((ret += tmp) > n) ret -= n;
        }
        if ((tmp <<= 1) > n) tmp -= n;
        y >>= 1;
    }
    return ret;
}
int mod(int a, int b, int c)
{
    int ret = 1;
    while (b)
    {
        if (b & 0x1)
            ret = mod_pro(ret, a, c);
        a = mod_pro(a, a, c);
        b >>= 1;
    }
    return ret;
}
int ran()
{
    int ret = rand();
    return ret * rand();
}
bool isPrime(int n, int times)
{
    if (n < 2) return false;
    if (n == 2) return true;
    if (!(n & 0x1)) return false;
    int k = 0, m, a, i;
    for (m = n - 1; !(m & 1); m >>= 1, k++);
    while (times--)
    {
        a = mod(ran() % (n - 2) + 2, m, n);
        if (a != 1)
        {
            for (i = 0; i < k && a != n - 1; i++)
                a = mod_pro(a, a, n);
            if (i >= k) return false;
        }
    }
    return true;
}
int main()
{
    int n;
    for (int i = 1; i <= 100; i++)
    {
        if (isPrime(i, 1))
            cout << i << " YES\n";
        else
            cout << i << " NO\n";
    }
    return 0;
}
