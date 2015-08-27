const int NV = 10005;
const int NE = NV;
int head[NV], ecnt;
struct edge
{
    int v, next;
} E[NE];

void addedge(int u, int v)
{
    ecnt++;
    E[ecnt].v = v;
    E[ecnt].next = head[u];
    head[u] = ecnt;
}

int l[NV], r[NV], p;
void dfs(int u)
{
    p++;
    l[u] = p;
    for (int i = head[u]; i != -1; i = E[i].next)
    {
        dfs(E[i].v);
    }
    r[u] = p;
}

void init()
{
    ecnt = p = 0;
    memset(head, -1, sizeof(head));
}
