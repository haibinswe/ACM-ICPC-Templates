/*==================================================*\
| 二分图匹配（Hopcroft-Karp的算法）
| INIT: g[][]邻接矩阵;
| CALL: res = Hopcroft_Karp(); NX, NY要初始化
| 可以改成下标为1
| 时间复杂度为O（V^0.5E）
\*==================================================*/
const int MAXN = 3001;
int g[MAXN][MAXN], mx[MAXN], my[MAXN], NX, NY;
int dx[MAXN], dy[MAXN], dis;
bool vis[MAXN];
bool searchP()
{
    queue<int> q;
    dis = inf;
    memset(dx, -1, sizeof(dx));
    memset(dy, -1, sizeof(dy));
    for (int i = 0; i < NX; i++)
    {
        if (mx[i] == -1)
        {
            q.push(i);
            dx[i] = 0;
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (dx[u] > dis) break;
        for (int v = 0; v < NY; v++)
        {
            if (g[u][v] && dy[v] == -1)
            {
                dy[v] = dx[u] + 1;
                if (my[v] == -1) dis = dy[v];
                else
                {
                    dx[my[v]] = dy[v] + 1;
                    q.push(my[v]);
                }
            }
        }
    }
    return dis != inf;
}
bool DFS(int u)
{
    for (int v = 0; v < NY; v++)
    {
        if (!vis[v] && g[u][v] && dy[v] == dx[u] + 1)
        {
            vis[v] = 1;
            if (my[v] != -1 && dy[v] == dis) continue;
            if (my[v] == -1 || DFS(my[v]))
            {
                my[v] = u;
                mx[u] = v;
                return 1;
            }
        }
    }
    return 0;
}
int Hopcroft_Karp()
{
    int ret = 0;
    memset(mx, -1, sizeof(mx));
    memset(my, -1, sizeof(my));
    while (searchP())
    {
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < NX; i++)
            if (mx[i] == -1 && DFS(i)) ret++;
    }
    return ret;
}
