/*****************************************************
二分图匹配（匈牙利算法的DFS实现）
INIT：g[][]两边定点划分的情况
CALL:res=hungary();输出最大匹配数
优点：适于稠密图，DFS找增广路快，实现简洁易于理解
时间复杂度:O(VE);
*****************************************************/
const int MAXN = 1000;
int uN, vN; //u,v数目
int g[MAXN][MAXN];//编号是0~n-1的
int linker[MAXN];
bool used[MAXN];
bool dfs(int u)
{
    for (int v = 0; v < vN; v++)
    {
        if (g[u][v] && !used[v])
        {
            used[v] = true;
            if (linker[v] == -1 || dfs(linker[v]))
            {
                linker[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hungary()
{
    int ret = 0;
    memset(linker, -1, sizeof(linker));
    for (int u = 0; u < uN; u++)
    {
        memset(used, 0, sizeof(used));
        if (dfs(u)) ret++;
    }
    return ret;
}

void init()
{
    memset(g, 0, sizeof(g));
}
