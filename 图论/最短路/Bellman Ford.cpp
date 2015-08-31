// 初始化：令m=0，然后使用addedge添加所有边（或直接初始化m,u,v,w）。
// 调用：Ford(start)。start是起点。如果有负环则返回false， 否则返回true。
// 注意：下标从0开始； 结果保存在d[]中
const int MAXN = 200, MAXM = 10000;
int u[MAXM], v[MAXM], w[MAXM];
int m = 0, n;
void AddEdge(int x, int y, int len)
{
    u[m] = x, v[m] = y, w[m] = len;
    m++;
}
int d[MAXN];
bool Ford(int start)
{
    memset(d, inf, sizeof(d));
    d[start] = 0;
    for (int k = 0; k < n - 1; k++)
    {
        for (int i = 0; i < m; i++) // 检查每条边
        {
            int &x = u[i], &y = v[i];
            if (d[x] < inf) d[y] = min(d[y], d[x] + w[i]);
        }
    }
    // 检查负环——如果全部松弛之后还能松弛,说明一定有负环
    for (int i = 0; i < m; i++)
    {
        int &x = u[i], &y = v[i];
        if (d[y] > d[x] + w[i]) return false;
    }
    return true;
}
