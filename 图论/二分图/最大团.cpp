const int N = 51;
struct MaxClique //base from 0
{
    int n, ne, maxn;
    int best[N], rec[N];
    bool link[N][N];
    MaxClique(int _n)
    {
        n = _n;
        memset(link, 0, szof(link));
    }
    void setn(int _n)
    {
        n = _n;
    }
    void Add(int u, int v)
    {
        link[u][v] = link[v][u] = true;
    }
    bool dfs(int n, int u[], int sz, int ret[])
    {
        if (n)
        {
            if (sz + best[u[0]] <= maxn) return false;
            int v[N], vn, i, j;
            for (i = 0; i < sz + n - maxn && i < n; i++)
            {
                for (vn = 0, j = i + 1; j < n; j++)
                {
                    if (link[u[i]][u[j]]) v[vn++] = u[j];
                }
                rec[sz] = u[i];
                if (dfs(vn, v, sz + 1, ret)) return true;
            }
        }
        else if (sz > maxn)
        {
            maxn = sz;
            for (int i = 0; i < sz; i++)
                ret[i] = rec[i];
            return true;
        }
        return false;
    }
    int Max_Clique(int ret[])
    {
        int v[N], vn, i, j;
        maxn = 0;
        for (i = n - 1; i >= 0; i--)
        {
            for (vn = 0, j = i + 1; j < n; j++)
            {
                if (link[i][j]) v[vn++] = j;
            }
            dfs(vn, v, 1, ret);
            best[i] = maxn;
        }
        return maxn;
    }
};
