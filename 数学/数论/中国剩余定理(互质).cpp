const int MAXN = 20;
int a[MAXN], m[MAXN], n;
int CRT(int a[], int m[], int n)
{
    int M = 1;
    for (int i = 0; i < n; i++) M *= m[i];
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        int tm = M / m[i];
        exgcd(tm, m[i], x, y);
        ret = (ret + tm * x * a[i]) % M;
    }
    return (ret + M) % M;
}
