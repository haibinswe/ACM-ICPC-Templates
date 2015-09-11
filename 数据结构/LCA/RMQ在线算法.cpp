// LCA_RMQ 在线算法 O(nlogn) - O(1)
// 此处为有向树，initLCA(n, r) 表示 n 个结点，r 为根
const int MAXN = 10005;
struct Edge
{
    int ed, next;
} E[MAXN];

int head[MAXN], nEdge;
int w[MAXN << 1], dp[MAXN << 1][20];
int d[MAXN << 1], p[MAXN << 1], l[MAXN], idx;
void init()
{
    memset(head, -1, sizeof(head));
    nEdge = 0;
}

void AddEdge(int a, int b)
{
    E[nEdge].ed = b;
    E[nEdge].next = head[a];
    head[a] = nEdge++;
}

void dfs(int x, int dep)
{
    int y;
    l[x] = idx;
    d[idx] = dep;
    p[idx] = x;
    ++idx;
    for (int i = head[x]; ~i; i = E[i].next)
    {
        if (l[y = E[i].ed] == -1)
        {
            dfs(y, dep + 1);
            d[idx] = dep;
            p[idx] = x;
            ++idx;
        }
    }
}

void initST(const int *d, int n)
{
    int i, j;
    for (w[0] = -1, i = 1; i <= n; ++i)
        w[i] = (i & (i - 1)) ? w[i - 1] : w[i - 1] + 1;
    for (i = 0; i < n; ++i) dp[i][0] = i;
    for (j = 1; (1 << j) <= n; ++j)
    {
        for (i = 0; i + (1 << j) <= n; ++i)
        {
            if (d[dp[i][j - 1]] < d[dp[i + (1 << (j - 1))][j - 1]])
                dp[i][j] = dp[i][j - 1];
            else
                dp[i][j] = dp[i + (1 << (j - 1))][j - 1];
        }
    }
}

void initLCA(int n, int r)
{
    memset(l, -1, sizeof(l));
    dfs(r, idx = 0);
    initST(d, idx);
}

int lca(int a, int b)
{
    int x;
    if (l[a] > l[b]) swap(a, b);
    x = w[l[b] - l[a] + 1];
    if (d[dp[l[a]][x]] < d[dp[l[b] - (1 << x) + 1][x]])
        return p[dp[l[a]][x]];
    else return p[dp[l[b] - (1 << x) + 1][x]];
}
