// ��ʼ����G��ʾ�ڽӾ���n��ʾ���������±��0��ʼ
// ��i��j�����ͨ����G[i][j]=false������G[i][j]=true
// ���ã�topocount()
const int MAXN = 20, M = 100001;
bool G[MAXN][MAXN];
int n;
int f[M];
bool err = false;
int encode(int *vis) // ״̬ѹ��
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
            num++; // �����ж�Ŀǰ��ͼ�Ƿ�ֻ��һ����
            int pre = 0;
            for (int j = 0; j < n; j++)
            {
                if ((!vis[j]) && G[j][i]) pre++;
            }
            // �洢���Ϊ0�ĵ㣬 ׼��������ɾ����
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
