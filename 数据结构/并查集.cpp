const int LEN = 1005;
int father[LEN], rk[LEN];
//非递归
int findset(int x)
{
    int k, j, r;
    r = x;
    while (r != father[r])
    {
        r = father[r];
    }
    k = x;
    while (k != r)
    {
        j = father[k];
        father[k] = r;
        k = j;
    }
    return r;
}

//递归
int findset(int x)
{
    return father[x] == x ? x : father[x] = findset(father[x]);
}

void unionset(int a, int b)
{
    a = findset(a);
    b = findset(b);
    if (a == b) return;
    if (rk[a] > rk[b]) father[b] = a;
    else
    {
        if (rk[a] == rk[b]) rk[b]++;
        father[a] = b;
    }
}

void init(int n)
{
    memset(rk, 0, sizeof(rk));
    for (int i = 1; i <= n; i++)
    {
        father[i] = i;
    }
}
