// ��ʼ����G��ʾ�ڽӾ���n��ʾ���������±��0��ʼ
// ��i��j�����ͨ����G[i][j]=false�� ����G[i][j]=true
// ���ã�find_circuit()�������ŷ��ͨ·�����������true
// ע�⣺�˺������ƻ�G��ֵ�����������ñ��ݡ�
const int MAXN = 1000;
bool G[MAXN][MAXN]; // �ڽӾ���
int n; // ������
// ����ͼ���ڽӾ������������ͨ,��Ϊ1,����Ϊ0
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
            if (G[i][j]) ++cnt[i]; // ͳ�ƽ�����
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
