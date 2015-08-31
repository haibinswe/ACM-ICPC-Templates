// ��ʼ����G��ʾ�ڽӾ���n��ʾ���������±��0��ʼ
// ��i��j�����ͨ����G[i][j]=false������G[i][j]=true
// ���ã�toposort()������л��򷵻�false������������������a�С�
const int MAXN = 1000;
bool G[MAXN][MAXN]; // �ڽӾ���
int n; // ������
int cnt[MAXN]; // cnt[i]��ʾ���i�����
int a[MAXN], a_n; // �������������a��
queue<int> q;
bool toposort()
{
    memset(cnt, 0, sizeof(cnt));
    a_n = 0;
    q = queue<int>();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (G[i][j]) cnt[j]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (cnt[i] == 0) q.push(i);
    }
    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        a[a_n++] = i;
        for (int j = 0; j < n; j++)
        {
            if (G[i][j])
            {
                cnt[j]--;
                if (cnt[j] == 0) q.push(j);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (cnt[i] != 0) return false;
    }
    return true;
}
