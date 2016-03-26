// 初始化：G表示邻接矩阵，n表示结点个数，下标从0开始
// 从i到j如果连通， 则G[i][j]=false， 否则G[i][j]=true
// 调用：toposort()，如果有环则返回false。排序结果保存在数组a中。
const int MAXN = 1000;
bool G[MAXN][MAXN]; // 邻接矩阵
int n; // 结点个数
int a[MAXN], a_n;
// 结点访问情况：0、1、2分别代表未访问、正在访问、已访问。
// 如果正在访问的点又被访问一次，说明有环。
int vis[MAXN];
bool DFS(int v)
{
    vis[v] = 1;
    for (int i = 0; i < n; i++)
    {
        if (G[i][v])
        {
            if (vis[i] == 1) return false;
            else if (!DFS(i)) return false;
        }
    }
    vis[v] = 2;
    a[a_n++] = v;
    return true;
}
bool toposort()
{
    memset(vis, 0, sizeof(vis));
    a_n = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i] && !DFS(i))
            return false;
    }
    return true;
}
