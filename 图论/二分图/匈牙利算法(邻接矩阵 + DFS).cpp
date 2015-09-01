/*****************************************************
����ͼƥ�䣨�������㷨��DFSʵ�֣�
INIT��g[][]���߶��㻮�ֵ����
CALL:res=hungary();������ƥ����
�ŵ㣺���ڳ���ͼ��DFS������·�죬ʵ�ּ���������
ʱ�临�Ӷ�:O(VE);
*****************************************************/
const int MAXN = 1000;
int uN, vN; //u,v��Ŀ
int g[MAXN][MAXN];//�����0~n-1��
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
