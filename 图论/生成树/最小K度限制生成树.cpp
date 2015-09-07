//POJ 1639
map<string, int> MAP;
const int N = 25;
struct Edge
{
    int s, t, w;
    int flag, next, idx;
    bool operator < (const Edge &y) const
    {
        return w < y.w;
    }
} E[N * N], item[N], G[N * N];
//E为kursker的所用的边，G为原图
int head[N], fa[N], flag[N];
int tot, V0, V0n, totN;
void AddEdge(int s, int t, int w)
{
    E[tot].s = s;
    E[tot].t = t;
    E[tot].w = w;
    E[tot].flag = 0;
    E[tot].idx = tot;
    G[tot] = E[tot];
    G[tot].next = head[s];
    head[s] = tot ++;
}

int findset(int x)
{
    if (fa[x] == x) return x;
    return fa[x] = findset(fa[x]);
}

bool unionset(int x, int y)
{
    x = findset(x);
    y = findset(y);
    if (x != y)
    {
        fa[x] = y;
        return 1;
    }
    return 0;
}

int dfs(int s, int pre, int e)
{
    int i, t;
    int j = e, maxn = pre;
    flag[s] = 1;
    for (i = head[s]; i != -1; i = G[i].next)
    {
        t = G[i].t;
        if (G[i].flag && !flag[t])
        {
            j = e, maxn = pre;
            if (t == V0) return e;
            if (G[i].w > maxn)
                j = i, maxn = G[i].w;
            j = dfs(t, maxn, j);
            if (j != -1) return j;
            flag[t] = 0;
        }
    }
    return -1;
}

int KMST(int k)
{
    int res, ans, tmp;
    int i, j, cnt = 0;
    for (j = head[V0], i = 0; j != -1; j = G[j].next, i++)
        item[i] = G[j];
    V0n = i;
    sort(E, E + tot);
    for (res = i = 0; i < tot; i ++)
    {
        if (E[i].s == V0 || E[i].t == V0) continue;
        if (unionset(E[i].s, E[i].t))
        {
            G[E[i].idx].flag  = 1;
            G[E[i].idx ^ 1].flag  = 1;
            res += E[i].w;
        }
    }
    sort(item, item + V0n);
    for (i = 0; i < V0n; i++)
    {
        if (unionset(item[i].s, item[i].t))
        {
            G[item[i].idx].flag = 1;
            G[item[i].idx ^ 1].flag  = 1;
            res += item[i].w;
            cnt ++;
        }
    }
    ans = res;
    while (cnt < k)
    {
        int mini = inf, mid, maxn;
        for (i = head[V0]; i != -1; i = G[i].next)
        {
            if (G[i].flag == 0)
            {
                memset(flag, 0, sizeof(flag));
                tmp = dfs(G[i].t, -inf, i);
                if (res - G[tmp].w + G[i].w < mini)
                {
                    mini = res - G[tmp].w + G[i].w;
                    mid = i;
                    maxn = tmp;
                }
            }
        }
        if (mini == inf) break;
        G[mid].flag = 1;
        G[mid ^ 1].flag = 1;
        G[maxn].flag = 0;
        G[maxn ^ 1].flag = 0;
        res = mini;
        if (res < ans) ans = res;
        cnt ++;
    }
    return ans;
}

void init()
{
    tot = 0;
    memset(head, -1, sizeof(head));
    for (int i = 0; i < N; i++)
    {
        fa[i] = i;
    }
    totN = 0;
    MAP.clear();
}

char str1[N], str2[N];
int main()
{
    int n, k;
    Edge e;
    while (~scanf("%d", &n))
    {
        init();
        for (int i = 0; i < n; i++)
        {
            scanf("%s%s%d", str1, str2, &e.w);
            if (!(e.s = MAP[str1])) e.s = MAP[str1] = ++totN;
            if (!(e.t = MAP[str2])) e.t = MAP[str2] = ++totN;
            AddEdge(e.s, e.t, e.w);
            AddEdge(e.t, e.s, e.w);
        }
        scanf("%d", &k);
        V0 = MAP["Park"];
        int ans = KMST(k);
        printf("Total miles driven: %d\n", ans);
    }
    return 0;
}
