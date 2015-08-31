const int NV = 105;
const int NE = 10005 * 2;
int dis[NV];
int pre[NV], vis[NV], head[NV], ecnt, pcnt;
struct Edge
{
    int v, next, l;
} E[NE];

void AddEdge(int u, int v, int l)
{
    E[++ecnt].v = v;
    E[ecnt].l = l;
    E[ecnt].next = head[u];
    head[u] = ecnt;
}

void init(int n, int m, int s)
{
    ecnt = 0;
    memset(pre, 0, sizeof(pre));
    memset(vis, 0, sizeof(vis));
    memset(head, -1, sizeof(head));
    for (int i = 0; i <= n; i++)
    {
        dis[i] = inf;
    }
    dis[s] = 0;
    for (int i = 1; i <= m; i++)
    {
        int u, v, l;
        scanf("%d%d%d", &u, &v, &l);
        AddEdge(u, v, l);
        AddEdge(v, u, l);
    }
}

struct Point
{
    int u, l;
    Point(int u, int l): u(u), l(l) {}
    bool operator < (const Point &p) const
    {
        return l > p.l;
    }
};

int Prim(int s)
{
    priority_queue<Point> q;
    q.push(Point(s, 0));
    int ans = 0;
    pcnt = 0;
    while (!q.empty())
    {
        Point p = q.top();
        q.pop();
        int u = p.u;
        if (vis[u]) continue;
        vis[u] = 1;
        ans += p.l;
        pcnt++;
        for (int i = head[u]; i != -1; i = E[i].next)
        {
            if (!vis[E[i].v] && E[i].l < dis[E[i].v])
            {
                dis[E[i].v] = E[i].l;
                pre[E[i].v] = u;
                q.push(Point(E[i].v, dis[E[i].v]));
            }
        }
    }
    return ans;
}

bool judge(int n)
{
    return pcnt == n;
}
