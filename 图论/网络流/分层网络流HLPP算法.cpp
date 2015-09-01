const int MAXN = 1515;
const int MAXM = 300300;
inline int RE(int i)
{
    return i ^ 1;
}

struct Edge
{
    int v, c;
};

struct FlowNetwork
{
    int n, m, source, sink;
    vector<int> e[MAXN];
    Edge edge[MAXM * 2];
    void init(int n, int source, int sink)
    {
        this->n = n;
        this->m = 0;
        this->source = source;
        this->sink = sink;
        for (int i = 0; i < n; ++i)
        {
            e[i].clear();
        }
    }
    void AddEdge(int a, int b, int c)
    {
        edge[m].v = b;
        edge[m].c = c;
        e[a].push_back(m++);
        edge[m].v = a;
        edge[m].c = 0;
        e[b].push_back(m++);
    }
    int c[MAXN * 2], d[MAXN], w[MAXN];
    int done[MAXN];
    void bfs()
    {
        queue<int> q;
        fill(c, c + n * 2, 0);
        c[n + 1] = n - 1;
        fill(d, d + n, n + 1);
        d1 = n;
        d[sink] = 0;
        q.push(sink);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            --c[n + 1];
            ++c[d[u]];
            for (size_t i = 0; i < e[u].size(); i++)
            {
                Edge &cra = edge[RE(e[u][i])];
                int v = edge[e[u][i]].v;
                if (d[v] == n + 1 && cra.c > 0)
                {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
    }
    int hlpp()
    {
        vector<queue<int> > q(n * 2);
        vector<bool> mark(n, false);
        int todo = -1;
        bfs();
        mark1 = mark[sink] = true;
        fill(w, w + n, 0);
        for (size_t i = 0; i < e1.size(); i++)
        {
            Edge &arc = edge[e1[i]];
            Edge &cra = edge[RE(e1[i])];
            int v = arc.v;
            w[v] += arc.c;
            cra.c += arc.c;
            arc.c = 0;
            if (!mark[v])
            {
                mark[v] = true;
                q[d[v]].push(v);
                todo = max(todo, d[v]);
            }
        }
        fill(done, done + n, 0);
        while (todo >= 0)
        {
            if (q[todo].empty())
            {
                --todo;
                continue;
            }
            int u = q[todo].front();
            mark[u] = false;
            q[todo].pop();
            while (done[u] < (int)e[u].size())
            {
                Edge &arc = edge[e[u][done[u]]];
                int v = arc.v;
                if (d[u] == d[v] + 1 && arc.c > 0)
                {
                    Edge &cra = edge[RE(e[u][done[u]])];
                    int f = min(w[u], arc.c);
                    w[u] -= f;
                    w[v] += f;
                    arc.c -= f;
                    cra.c += f;
                    if (!mark[v])
                    {
                        mark[v] = true;
                        q[d[v]].push(v);
                    }
                    if (w[u] == 0) break;
                }
                ++done[u];
            }
            if (w[u] > 0)
            {
                int du = d[u];
                --c[d[u]];
                d[u] = n * 2;
                for (size_t i = 0; i < e[u].size(); i++)
                {
                    Edge &arc = edge[e[u][i]];
                    int v = arc.v;
                    if (d[u] > d[v] + 1 && arc.c > 0)
                    {
                        d[u] = d[v] + 1;
                        done[u] = i;
                    }
                }
                ++c[d[u]];
                if (c[du] == 0)
                {
                    for (int i = 0; i < n; ++i)
                    {
                        if (d[i] > du && d[i] < n + 1)
                        {
                            --c[d[i]];
                            ++c[n + 1];
                            d[i] = n + 1;
                        }
                    }
                }
                mark[u] = true;
                q[d[u]].push(u);
                todo = d[u];
            }
        }
        return w[sink];
    }
};

int main()
{
    int re;
    int n, m, l, r, s, t;
    FlowNetwork fn;
    scanf("%d", &re);
    for (int ri = 1; ri <= re; ri++)
    {
        if (ri > 1) printf("\n");
        scanf("%d%d%d", &n, &m, &l);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &r);
            if (r == 1) s = i;
            else if (r == l) t = i;
        }
        fn.init(n, s, t);
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &s, &t, &r);
            fn.AddEdge(s - 1, t - 1, r);
        }
        fn.hlpp();
        for (int i = 0; i < m; i++)
        {
            printf("%d\n", fn.edge[RE(i << 1)].c);
        }
    }
    return 0;
}
