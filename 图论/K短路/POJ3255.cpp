#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, n) for (int i = 1; i <= n; i++)
#define ForK(i, k, n) for (int i = k; i <= n; i++)
#define ForD(i, n) for (int i = n; i >= 0; i--)
#define Rep(i, n) for (int i = 0; i < n; i++)
#define RepD(i, n) for (int i = n; i >= 0; i--)
#define MemI(a) memset(a, 0, sizeof(a))
#define MemC(a) memset(a, '\0', sizeof(a))
#define debug(x) cout<<"--- "<<x<<" ---"<<endl
#define PI acos(-1.0)
#define eps 1e-8
#define inf 0x3f3f3f3f
typedef long long ll;
using namespace std;

const int NV = 5010;
const int NE = 100010;
int n, m, ecnt, src, des, K;
int head[NV], vis[NV], dis[NV];
struct Edge
{
    int v, next, l;
} E[NE << 1];

struct Data
{
    int v, g, h;
    bool operator < (const Data &a) const
    {
        return a.g + a.h < g + h;
    }
};

void AddEdge(int u, int v, int l)
{
    E[ecnt].v = v;
    E[ecnt].l = l;
    E[ecnt].next = head[u];
    head[u] = ecnt++;
}

void Dijkstra()
{
    dis[des] = 0;
    for (int i = 1; i <= n; i++)
    {
        int k = 0;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && dis[k] > dis[j]) k = j;
        }
        vis[k] = 1;
        for (int u = head[k]; u != -1; u = E[u].next)
        {
            int v = E[u].v;
            if (!vis[v] && dis[v] > dis[k] + E[u].l)
                dis[v] = dis[k] + E[u].l;
        }
    }
}

int cnt[NV];
int Astar()
{
    priority_queue<Data> q;
    Data cur, next;
    cur.v = src;
    cur.g = 0;
    cur.h = dis[src];
    q.push(cur);
    while (!q.empty())
    {
        cur = q.top();
        q.pop();
        cnt[cur.v]++;
        if (cnt[cur.v] > K) continue;
        if (cnt[des] == K) return cur.g;
        for (int u = head[cur.v]; u != -1; u = E[u].next)
        {
            int v = E[u].v;
            next.v = v;
            next.g = cur.g + E[u].l;
            next.h = dis[v];
            q.push(next);
        }
    }
    return 0;
}

void init(int m, int s, int e, int k)
{
    ecnt = 0;
    memset(head, -1, sizeof(head));
    memset(cnt, 0, sizeof(cnt));
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= m; i++)
    {
        int u, v, l;
        scanf("%d%d%d", &u, &v, &l);
        AddEdge(u, v, l);
        AddEdge(v, u, l);
    }
    src = s;
    des = e;
    K = k;
}

int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        init(m, 1, n, 2);
        Dijkstra();
        int ans = Astar();
        printf("%d\n", ans);
    }
    return 0;
}
