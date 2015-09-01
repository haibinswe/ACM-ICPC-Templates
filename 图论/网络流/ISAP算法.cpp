const int maxn = 1000;
const int maxm = 10000;
int m;
struct Node
{
    int v;      // vertex
    int cap;    // capacity
    int flow;   // current flow in this arc
    int next;
} e[maxm * 2];

int g[maxn], cnt;
int st, ed, n;
void AddEdge(int u, int v, int c)
{
    e[++cnt].v = v;
    e[cnt].cap = c;
    e[cnt].flow = 0;
    e[cnt].next = g[u];
    g[u] = cnt;
    e[++cnt].v = u;
    e[cnt].cap = 0;
    e[cnt].flow = 0;
    e[cnt].next = g[v];
    g[v] = cnt;
}

void init()
{
    memset(g, 0, sizeof(g));
    cnt = 1;
    st = 1, ed = n;
    int u, v, c;
    while (m--)
    {
        scanf("%d%d%d", &u, &v, &c);
        AddEdge(u, v, c);
    }
    n = n + 3; //这里可以将n适当扩大一些
}

int dist[maxn], numbs[maxn], q[maxn];
void rev_bfs()
{
    int font = 0, rear = 1;
    for (int i = 0; i <= n; i++)   //n为总点数
    {
        dist[i] = maxn;
        numbs[i] = 0;
    }
    q[font] = ed;
    dist[ed] = 0;
    numbs[0] = 1;
    while (font != rear)
    {
        int u = q[font++];
        for (int i = g[u]; i; i = e[i].next)
        {
            if (e[i ^ 1].cap == 0 || dist[e[i].v] < maxn) continue;
            dist[e[i].v] = dist[u] + 1;
            ++numbs[dist[e[i].v]];
            q[rear++] = e[i].v;
        }
    }
}

int maxflow()
{
    rev_bfs();
    int u, totalflow = 0;
    int curg[maxn], revpath[maxn];
    for (int i = 0; i <= n; i++)
    {
        curg[i] = g[i];
    }
    u = st;
    while (dist[st] < n)
    {
        if (u == ed)     // find an augmenting path
        {
            int augflow = INF;
            for (int i = st; i != ed; i = e[curg[i]].v)
            {
                augflow = min(augflow, e[curg[i]].cap);
            }
            for (int i = st; i != ed; i = e[curg[i]].v)
            {
                e[curg[i]].cap -= augflow;
                e[curg[i] ^ 1].cap += augflow;
                e[curg[i]].flow += augflow;
                e[curg[i] ^ 1].flow -= augflow;
            }
            totalflow += augflow;
            u = st;
        }
        int i;
        for (i = curg[u]; i; i = e[i].next)
        {
            if (e[i].cap > 0 && dist[u] == dist[e[i].v] + 1) break;
        }
        if (i)   // find an admissible arc, then Advance
        {
            curg[u] = i;
            revpath[e[i].v] = i ^ 1;
            u = e[i].v;
        }
        else    // no admissible arc, then relabel this vertex
        {
            if (0 == (--numbs[dist[u]])) break;    // GAP cut, Important!
            curg[u] = g[u];
            int mindist = n;
            for (int j = g[u]; j; j = e[j].next)
            {
                if (e[j].cap > 0) mindist = min(mindist, dist[e[j].v]);
            }
            dist[u] = mindist + 1;
            ++numbs[dist[u]];
            if (u != st) u = e[revpath[u]].v;    // Backtrack
        }
    }
    return totalflow;
}

int main()
{
    while (~scanf("%d%d", &m, &n))
    {
        init();
        cout << maxflow() << endl;
    }
    return 0;
}

//最大流的输出路径
int out[maxm][3], tot = 0;
void get_out()
{
    for (int u = 1; u < ed; u++)
    {
        for (int i = g[u]; i; i = e[i].next)
        {
            if (e[i].v != ed && e[i].flow > 0)
            {
                out[tot][0] = u;
                out[tot][1] = e[i].v;
                out[tot++][2] = e[i].flow;
            }
        }
    }
}
