const int LEN = 1005;
int f[LEN], rk[LEN];
//非递归
int finds(int x)
{
    int k, j, r;
    r = x;
    while(r != f[r])
    {
        r = f[r];
    }
    k = x;
    while(k != r)
    {
        j = f[k];
        f[k] = r;
        k = j;
    }
    return r;
}

//递归
int finds(int x)
{
    return f[x] == x ? x : f[x] = finds(f[x]);
}

void join(int a, int b)
{
    a = finds(a);
    b = finds(b);
    if (a == b)
    {
        return;
    }
    if (rk[a] > rk[b])
    {
        f[b] = a;
    }
    else
    {
        if (rk[a] == rk[b])
        {
            rk[b]++;
        }
        f[a] = b;
    }
}

void init(int n)
{
    memset(rk, 0, sizeof(rk));
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
    }
}
