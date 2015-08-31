// 初始化：G表示邻接矩阵，n表示结点个数，下标从0开始
// 从i到j如果连通，则G[i][j]=false，否则G[i][j]=true
// 调用：topocount()
const int MAXN = 20, M = 100001;
bool G[MAXN][MAXN];
int n;
int f[M];
bool err = false;
int encode(int *vis) // 状态压缩
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0) c |= 1 << i;
    }
    return c;
}
int DFS(int *vis)
{
    int p = encode(vis);
    if (f[p]) return f[p];
    int num = 0, m = 0, tmp[MAXN];
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            num++; // 用于判断目前的图是否只有一个点
            int pre = 0;
            for (int j = 0; j < n; j++)
            {
                if ((!vis[j]) && G[j][i]) pre++;
            }
            // 存储入度为0的点， 准备到后面删除。
            if (!pre) tmp[m++] = i;
        }
    }
    if (!m)
    {
        err = true;
        return 0;
    }
    if (num == 1) return f[p] = 1;
    else
    {
        int sum = 0;
        for (int i = 0; i < m; i++)
        {
            vis[tmp[i]] = 1;
            sum += DFS(vis);
            vis[tmp[i]] = 0;
            if (err) return 0;
        }
        return f[p] = sum;
    }
}
int topocount()
{
    int vis[MAXN] = {0};
    memset(f, 0, sizeof(f));
    err = false;
    DFS(vis);
    return f[encode(vis)];
}
