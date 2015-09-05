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
#define PI acos(-1)
#define eps 1e-8
#define inf 0x3f3f3f3f
typedef long long ll;
using namespace std;

const int NV = 1005;
const int NE = 200005;
struct Edge
{
    int v, c, next;
} E[NE];

int head[NV], tail[NV], dis[NV];
bool vis[NV];
int ecnt;
struct Data
{
    int v, d, h;
    bool operator < (const Data &a) const
    {
        return a.d + a.h < d + h;
    }
};

void AddEdge(int u, int v, int c)
{
    E[ecnt].v = v;
    E[ecnt].c = c;
    E[ecnt].next = head[u];
    head[u] = ecnt++;
    E[ecnt].v = u;
    E[ecnt].c = c;
    E[ecnt].next = tail[v];
    tail[v] = ecnt++;
}

void Dijstra(int n, int s, int t)
{
    dis[t] = 0;
    for (int i = 1; i <= n; i++)
    {
        int k = 0;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && dis[k] > dis[j]) k = j;
        }
        vis[k] = true;
        for (int temp = tail[k]; temp != -1; temp = E[temp].next)
        {
            int v = E[temp].v;
            if (dis[v] > dis[k] + E[temp].c)
                dis[v] = dis[k] + E[temp].c;
        }
    }
}

int cnt[NV];
int Astar(int n, int s, int t, int K)
{
    Data cur, next;
    priority_queue<Data> Q;
    cur.v = s;
    cur.d = 0;
    cur.h = dis[s];
    Q.push(cur);
    while (!Q.empty())
    {
        cur = Q.top();
        Q.pop();
        cnt[cur.v]++;
        if (cnt[cur.v] > K) continue;
        if (cnt[t] == K) return cur.d;
        for (int temp = head[cur.v]; temp != -1; temp = E[temp].next)
        {
            int v = E[temp].v;
            next.d = cur.d + E[temp].c;
            next.v = v;
            next.h = dis[v];
            Q.push(next);
        }
    }
    return -1;
}

void init(int m)
{
    ecnt = 0;
    memset(head, -1, sizeof(head));
    memset(tail, -1, sizeof(tail));
    memset(cnt, 0, sizeof(cnt));
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= m; i++)
    {
        int u, v, l;
        scanf("%d%d%d", &u, &v, &l);
        AddEdge(u, v, l);
    }
}

int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        init(m);
        int s, t, k;
        scanf("%d%d%d", &s, &t, &k);
        if (s == t) k++;
        Dijstra(n, s, t);
        printf("%d\n", Astar(n, s, t, k));
    }
    return 0;
}
