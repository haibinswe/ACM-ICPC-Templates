const int MAXN = 1000;
int a[MAXN], m[MAXN], n;
int CRT(int a[], int m[], int n)
{
    if (n == 1)
    {
        if (m[0] > a[0]) return a[0];
        else return -1;
    }
    int x, y, d;
    for (int i = 1; i < n; i++)
    {
        if (m[i] <= a[i]) return -1;
        d = exgcd(m[0], m[i], x, y);
        if ((a[i] - a[0]) % d != 0) return -1;
        int t = m[i] / d;
        x = ((a[i] - a[0]) / d * x % t + t) % t;
        a[0] = x * m[0] + a[0];
        m[0] = m[0] * m[i] / d;
        a[0] = (a[0] % m[0] + m[0]) % m[0];
    }
    return a[0];
}
