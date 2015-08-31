const int N = 1005;
int g[N][N], f[N][N], path[N][N];
void init(int n, int m)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            g[i][j] = i == j ? 0 : inf;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, l;
        scanf("%d%d%d", &u, &v, &l);
        g[u][v] = l;
        g[v][u] = l;
    }
    memcpy(f, g, sizeof(g));
}

void FloydWarshall(int n)
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (f[i][k] != inf && f[k][j] != inf && f[i][k] + f[k][j] < f[i][j])
                    f[i][j] = f[i][k] + f[k][j], path[i][j] = path[i][k];
            }
        }
    }
}

void showPath(int u, int v)
{
    int tmp = u;
    printf("%d", u);
    while (tmp != v)
    {
        printf("-->%d", path[tmp][v]);
        tmp = path[tmp][v];
    }
}
