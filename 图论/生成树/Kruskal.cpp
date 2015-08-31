const int NV = 105;
const int NE = 10005;
struct Edge
{
    int u, v, l;
    bool operator < (const Edge e) const
    {
        return l < e.l;
    }
} E[NE];

int f[NV], rk[NV];
int findset(int x)
{
    return f[x] == x ? x : f[x] = findset(f[x]);
}

void unionset(int a, int b)
{
    a = findset(a);
    b = findset(b);
    if (a == b) return;
    if (rk[a] > rk[b]) f[b] = a;
    else
    {
        if (rk[a] == rk[b]) rk[b]++;
        f[a] = b;
    }
}

void init(int n, int m)
{
    memset(rk, 0, sizeof(rk));
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].l);
    }
}

int kruskal(int n, int m)
{
    sort(E + 1, E + m + 1);
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        if (findset(E[i].u) != findset(E[i].v))
        {
            unionset(E[i].u, E[i].v);
            ans += E[i].l;
        }
    }
    return ans;
}

bool judge(int n)
{
    int flag = 0;
    for (int i = 1; i <= n; i++)
    {
        if (findset(i) == i) flag++;
    }
    return flag == 1;
}
