const int NV = 128;
const int NE = 1024;
const int M = 31011;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
long long d[NV][NV], dis[NV];
int pre[NV], mat[NV][NV];
bool vis[NV];
map<long long, int> genMat[NV][NV];

void init(int n)
{
    memset(mat, 0, sizeof(mat));
    memset(d, 0x3f, sizeof(d));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            genMat[i][j].clear();
    }
}

void polyAdd(map<long long, int> &a, map<long long, int> &b)
{
    map<long long, int>::iterator i, j, p;
    for (i = a.begin(), j = b.begin(); i != a.end() && j != b.end(); )
    {
        if (i->first < j->first) i++;
        else if (j->first < i->first) a.insert(*(j++));
        else
        {
            p = i;
            ++p;
            i->second += (j++)->second;
            if (!i->second) a.erase(i);
            i = p;
        }
    }
    for ( ; j != b.end(); j++) a.insert(*j);
}

void polyAdd(map<long long, int> &a, long long x, int y)
{
    map<long long, int>::iterator it = a.find(x);
    if (it != a.end()) it->second += y;
    else a.insert(make_pair(x, y));
}

long long prim(int n, int src)
{
    int x;
    long long v, ret = 0;
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[src] = 0;
    pre[src] = -1;
    for (int i = 0; i < n; i++)
    {
        v = INF;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && v > dis[j]) v = dis[x = j];
        }
        ret += dis[x];
        vis[x] = true;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && dis[j] > d[x][j])
                dis[j] = d[pre[j] = x][j];
        }
    }
    return ret;
}

void dfs(int n, int x)
{
    map<long long, int>::iterator it;
    for (int i = 0; i < n; i++)
    {
        if (!(pre[i] ^ x)) dfs(n, i);
    }
    if (~pre[x])
    {
        long long v = INF;
        for (int i = 0; i < n; i++)
        {
            if (!genMat[i][x].empty())
                v = min(v, genMat[i][x].begin()->first);
        }
        for (int i = 0; i < n; i++)
        {
            polyAdd(genMat[i][pre[x]], genMat[i][x]);
            it = genMat[i][x].find(v);
            if (it != genMat[i][x].end()) mat[i][x] = it->second;
        }
    }
}

int det(int a[NV][NV], int n, int p)
{
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for ( ; a[j][i]; ans = -ans)
            {
                int t = a[i][i] / a[j][i];
                for (int k = 0; k < n; k++)
                {
                    a[i][k] = (a[i][k] - a[j][k] * t) % p;
                    swap(a[i][k], a[j][k]);
                }
            }
        }
        if (!a[i][i]) return 0;
        ans = ans * a[i][i] % p;
    }
    return (ans % p + p) % p;
}

int solve(int n)
{
    prim(n, n - 1);
    dfs(n, n - 1);
    return det(mat, n - 1, M);
}

int main()
{
    int n, m, a, b;
    long long w;
    while (~scanf("%d%d", &n, &m))
    {
        init(n);
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%lld", &a, &b, &w);
            d[--a][--b] = d[b][a] = w;
            polyAdd(genMat[a][a], w, 1);
            polyAdd(genMat[b][b], w, 1);
            polyAdd(genMat[a][b], w, -1);
            polyAdd(genMat[b][a], w, -1);
        }
        printf("%d\n", solve(n));
    }
    return 0;
}
