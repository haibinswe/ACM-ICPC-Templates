//HDU 3478
const int MAXN = 1005;
vector<int> g[MAXN];
int color[MAXN];
//是二分图则返回1
int bfs(int s)
{
    queue<int> q;
    memset(color, -1, sizeof(color));
    color[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int pre = q.front();
        q.pop();
        for (int i = 0; i < g[pre].size(); i++)
        {
            int v = g[pre][i];
            if (color[pre] == color[v]) return 0;
            if (color[v] == -1)
            {
                color[v] = color[pre] ^ 1;
                q.push(v);
            }
        }
    }
    return 1;
}

//是二分图则返回0,有奇圈则返回1
int dfs(int u, int clr)
{
    color[u] = clr;
    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if (color[v] != -1 && color[v] == color[u]) return 1;
        if (color[v] == -1 && dfs(v, clr ^ 1)) return 1;
    }
    return 0;
}
