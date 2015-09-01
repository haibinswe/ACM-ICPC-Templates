const int MAXN = 1005;
vector<int> g[MAXN];
int linker[MAXN];
bool used[MAXN];
bool dfs(int u)
{
    for (int v = 0; v < g[u].size(); v++)
    {
        if (!used[g[u][v]])
        {
            used[g[u][v]] = true;
            if (linker[g[u][v]] == -1 || dfs(linker[g[u][v]]))
            {
                linker[g[u][v]] = u;
                return true;
            }
        }
    }
    return false;
}

int hungary(int n)
{
    int ret = 0;
    memset(linker, -1, sizeof(linker));
    for (int u = 1; u <= n; u++)
    {
        memset(used, 0, sizeof(used));
        if (dfs(u)) ret++;
    }
    return ret;
}

void init(int n)
{
    for (int i = 0; i <= n; i++)
    {
        g[i].clear();
    }
}
