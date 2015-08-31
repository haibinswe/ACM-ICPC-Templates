const int NV = 1005;
int pre[NV], vis[NV];
int dis[NV], g[NV][NV], f[NV][NV];
int use[NV][NV];
void init(int n, int m, int s)
{
    memset(pre, -1, sizeof(pre));
    memset(vis, 0, sizeof(vis));
    memset(use, 0, sizeof(use));
    memset(f, 0, sizeof(f));
    for (int i = 0; i <= n; i++)
    {
        dis[i] = inf;
    }
    dis[s] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            g[i][j] = inf;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, l;
        scanf("%d%d%d", &u, &v, &l);
        g[u][v] = l;
        g[v][u] = l;
        use[v][u] = 1;
        use[u][v] = 1;
    }
}

int Prim(int n)
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int u = 0;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && dis[j] < dis[u]) u = j;
        }

        if (pre[u] != -1)
        {
            use[pre[u]][u] = 2;
            use[u][pre[u]] = 2;
            for (int j = 1; j <= n; j++)
            {
                if (vis[j]) f[j][u] = max(f[j][pre[u]], g[pre[u]][u]);
            }
        }

        vis[u] = 1;
        ans += dis[u];
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && g[u][j] < dis[j])
            {
                dis[j] = g[u][j];
                pre[j] = u;
            }
        }
    }
    return ans;
}

int Prim2nd(int n, int prim)
{
    int ans = inf;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (use[i][j] == 1) ans = min(ans, prim + g[i][j] - f[i][j]);
        }
    }
    return ans;
}