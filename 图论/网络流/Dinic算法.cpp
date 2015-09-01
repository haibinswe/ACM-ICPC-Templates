const int NV = 20005;
const int NE = 500005;
int head[NV], ecnt;
int src, sink;
struct Edge
{
    int v, next, f;
} E[2 * NE];

void AddEdge(int u, int v, int c)
{
    E[++ecnt].v = v;
    E[ecnt].f = c;
    E[ecnt].next = head[u];
    head[u] = ecnt;
    E[++ecnt].v = u;
    E[ecnt].f = 0;
    E[ecnt].next = head[v];
    head[v] = ecnt;
}

void init(int n, int m)
{
    ecnt = 0;
    memset(head, -1, sizeof(head));
    src = 1, sink = n;
    for (int i = 1; i <= m; i++)
    {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        AddEdge(u, v, c);
    }
}

queue<int> que;
bool vis[NV];
int dis[NV];
void bfs()
{
    memset(dis, 0, sizeof(dis));
    while (!que.empty())
    {
        que.pop();
    }
    vis[src] = 1;
    que.push(src);
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        for (int i = head[u]; i != -1; i = E[i].next)
        {
            if (E[i].f && !vis[E[i].v])
            {
                que.push(E[i].v);
                dis[E[i].v] = dis[u] + 1;
                vis[E[i].v] = 1;
            }
        }
    }
}

int dfs(int u, int delta)
{
    if (u == sink) return delta;
    else
    {
        int ret = 0;
        for (int i = head[u]; delta && i != -1; i = E[i].next)
        {
            if (E[i].f && dis[E[i].v] == dis[u] + 1)
            {
                int dd = dfs(E[i].v, min(E[i].f, delta));
                E[i].f -= dd;
                E[(i + 1) ^ 1 - 1].f += dd;
                delta -= dd;
                ret += dd;
            }
        }
        return ret;
    }
}

int maxflow()
{
    int ret = 0;
    while (true)
    {
        memset(vis, 0, sizeof(vis));
        bfs();
        if (!vis[sink]) return ret;
        ret += dfs(src, inf);
    }
}
