const int NV = 40005;
const int NE = NV;
const int NQ = 10005;
int dis[NV], ans[NV];
int vis[NV], head[NV], hq[NV], ecnt, qcnt;
struct Edge
{
    int v, next, l;
} E[2 * NE];

struct Query
{
    int v, next, i;
} Q[2 * NQ];

void AddEdge(int u, int v, int l)
{
    E[++ecnt].v = v;
    E[ecnt].l = l;
    E[ecnt].next = head[u];
    head[u] = ecnt;
}

void AddQuery(int u, int v, int i)
{
    Q[++qcnt].v = v;
    Q[qcnt].i = i;
    Q[qcnt].next = hq[u];
    hq[u] = qcnt;
}

int fa[NV], rk[NV];
void init(int n, int m)
{
    ecnt = 0;
    qcnt = 0;
    memset(vis, 0, sizeof(vis));
    memset(rk, 0, sizeof(rk));
    memset(head, -1, sizeof(head));
    memset(hq, -1, sizeof(hq));
    for (int i = 1; i <= m; i++)
    {
        int u, v, l = 1, c;
        scanf("%d%d%d %c", &u, &v, &l, &c);
        AddEdge(u, v, l);
        AddEdge(v, u, l);
    }
}

int findset(int x)
{
    return fa[x] == x ? x : fa[x] = findset(fa[x]);
}

void Tarjan(int u, int d)
{
    dis[u] = d;
    fa[u] = u;
    vis[u] = 1;
    for (int i = head[u]; i != -1; i = E[i].next)
    {
        if (!vis[E[i].v]) Tarjan(E[i].v, d + E[i].l), fa[E[i].v] = u;
    }
    for (int i = hq[u]; i != -1; i = Q[i].next)
    {
        if (vis[Q[i].v]) ans[Q[i].i] = dis[u] + dis[Q[i].v] - 2 * dis[findset(Q[i].v)];
    }
}

void solve(int n, int m)
{
    init(n, m);
    int k;
    scanf("%d", &k);
    for (int i = 1; i <= k; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        AddQuery(u, v, i);
        AddQuery(v, u, i);
    }
    Tarjan(1, 0);
    for (int i = 1; i <= k; i++)
    {
        printf("%d\n", ans[i]);
    }
}

int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        solve(n, m);
    }
    return 0;
}
