const int NV = 30005;
const int NE = 100005;
int ecnt, head[NV];
int ans[NV], in[NV];
priority_queue<int> Q;
struct Edge
{
    int v, next;
} E[NE];

void init()
{
    memset(head, 0, sizeof(head));
    memset(in, 0, sizeof(in));
    ecnt = 1;
}

void AddEdge(int u, int v)
{
    E[++ecnt].v = v;
    E[ecnt].next = head[u];
    head[u] = ecnt;
    in[v]++;
}

int toposort(int n)
{
    while (!Q.empty()) Q.pop();
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0) Q.push(i);
    }
    int tot = 0;
    while (!Q.empty())
    {
        int u = Q.top();
        Q.pop();
        ans[tot++] = u;
        for (int i = head[u]; i; i = E[i].next)
        {
            if (in[E[i].v] > 0)
            {
                in[E[i].v]--;
                if (in[E[i].v] == 0) Q.push(E[i].v);
            }
        }
    }
    return tot;
}

int main()
{
    int t, m, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        init();
        while (m--)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            AddEdge(b, a);
        }
        int cnt = toposort(n);
        for (int i = cnt - 1; i >= 0; i--)
        {
            printf("%d%c", ans[i], " \n"[i == 0]);
        }
    }
    return 0;
}
