//非递归版本
int gcd(int m, int n)
{
    if (n == 0) return m;
    while (n > 0)
    {
        int tmp = m % n;
        m = n;
        n = tmp;
    }
    return m;
}
//递归版本
int gcd(int m, int n)
{
    return n ? gcd(n, m % n) : m;
}

int lcm(int m, int n)
{
    return m * n / gcd(m, n);
}
