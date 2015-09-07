const int MAXN = 1002;
const int MAXM = 40002;
struct Edge
{
    int u, v, cap, cost;
    int next;
} E[MAXM << 2];

int ecnt, sumFLow;
int head[MAXN], dist[MAXN], pp[MAXN];
bool vis[MAXN];
void init()
{
    ecnt = 0;
    memset(head, -1, sizeof(head));
}

void AddEdge(int u, int v, int cap, int cost)
{
    E[ecnt].u = u;
    E[ecnt].v = v;
    E[ecnt].cap = cap;
    E[ecnt].cost = cost;
    E[ecnt].next = head[u];
    head[u] = ecnt++;
    E[ecnt].u = v;
    E[ecnt].v = u;
    E[ecnt].cap = 0;
    E[ecnt].cost = -cost;
    E[ecnt].next = head[v];
    head[v] = ecnt++;
}

bool SPFA(int s, int t, int n)
{
    int u, v;
    queue<int> Q;
    memset(vis, false, sizeof(vis));
    memset(pp, -1, sizeof(pp));
    memset(dist, 0x3f, sizeof(dist));
    vis[s] = true;
    dist[s] = 0;
    Q.push(s);
    while (!Q.empty())
    {
        u = Q.front();
        Q.pop();
        vis[u] = false;
        for (int i = head[u]; i != -1; i = E[i].next)
        {
            v = E[i].v;
            if (E[i].cap && dist[v] > dist[u] + E[i].cost)
            {
                dist[v] = dist[u] + E[i].cost;
                pp[v] = i;
                if (!vis[v])
                {
                    Q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    if (dist[t] == inf) return false;
    return true;
}
//返回最小费用
int MCMF(int s, int t, int n)
{
    int fLow = 0; //总流量
    int minfLow, mincost;
    mincost = 0;
    while (SPFA(s, t, n))
    {
        minfLow = inf + 1;
        for (int i = pp[t]; i != -1; i = pp[E[i].u])
        {
            if (E[i].cap < minfLow) minfLow = E[i].cap;
        }
        fLow += minfLow;
        for (int i = pp[t]; i != -1; i = pp[E[i].u])
        {
            E[i].cap -= minfLow;
            E[i ^ 1].cap += minfLow;
        }
        mincost += dist[t] * minfLow;
    }
    sumFLow = fLow; //总流量
    return mincost;
}
