// 初始化：G表示邻接矩阵，n表示结点个数，下标从0开始
// 从i到j如果连通，则G[i][j]=false， 否则G[i][j]=true
// 调用：find_circuit()，如果有欧拉通路则输出并返回true
// 注意：此函数会破坏G的值，请事先做好备份。
const int MAXN = 1000;
bool G[MAXN][MAXN]; // 邻接矩阵
int n; // 结点个数
// 无向图的邻接矩阵。如果两点连通,则为1,否则为0
int cnt[MAXN];
int circuit[MAXN], pos;
void search(int i)
{
    circuit[pos++] = i;
    for (int j = 0; j < n; j++)
    {
        if (G[i][j])
        {
            G[i][j] = G[j][i] = false;
            search(j);
        }
    }
}
bool find_circuit()
{
    int start = 0, oddnumber = 0;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (G[i][j]) ++cnt[i]; // 统计结点入度
    }
    for (int i = 0; i < n; i++)
    {
        if (cnt[i] % 2 == 1) start = i, ++oddnumber;
    }
    if (oddnumber > 2 or oddnumber == 1) return false;
    else
    {
        pos = 0;
        search(start);
        for (int i = 0; i < pos; i++) cout << circuit[i] << "--->";
        return true;
    }
}
