// ��ʼ����G��ʾ�ڽӾ���n��ʾ���������±��0��ʼ
// ��i��j�����ͨ�� ��G[i][j]=false�� ����G[i][j]=true
// ���ã�toposort()������л��򷵻�false������������������a�С�
const int MAXN = 1000;
bool G[MAXN][MAXN]; // �ڽӾ���
int n; // ������
int a[MAXN], a_n;
// �����������0��1��2�ֱ����δ���ʡ����ڷ��ʡ��ѷ��ʡ�
// ������ڷ��ʵĵ��ֱ�����һ�Σ�˵���л���
int vis[MAXN];
bool DFS(int v)
{
    vis[v] = 1;
    for (int i = 0; i < n; i++)
    {
        if (G[i][v])
        {
            if (vis[i] == 1) return false;
            else if (vis[i] == 0) if (not DFS(i)) return false;
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
