//HDU 2222
const int N = 5000005;
const int M = 26;
struct AhoCorasickAutomata
{
    int ch[N][M], fail[N], val[N];
    int sz;
    void init()
    {
        sz = 1;
        memset(ch[0], 0, sizeof(ch[0]));
        memset(val, 0, sizeof(val));
    }
    int idx(char c)
    {
        return c - 'a';
    }
    void insert(char *s)
    {
        int n, now = 0;
        n = strlen(s);
        for (int i = 0; i < n; i++)
        {
            int id = idx(s[i]);
            if (ch[now][id] == 0)
            {
                memset(ch[sz], 0, sizeof(ch[sz]));
                ch[now][id] = sz++;
            }
            now = ch[now][id];
        }
        val[now]++;
    }
    void build()
    {
        queue<int> que;
        fail[0] = 0;
        for (int i = 0; i < M; i++)
        {
            int u = ch[0][i];
            if (u)
            {
                fail[u] = 0;
                que.push(u);
            }
        }
        while (!que.empty())
        {
            int r = que.front();
            que.pop();
            for (int c = 0; c < M; c++)
            {
                int u = ch[r][c];
                if (!u) continue;
                que.push(u);
                int v = fail[r];
                while (v && !ch[v][c]) v = fail[v];
                fail[u] = ch[v][c];
            }
        }
    }
    int query(char *s)
    {
        int n, now = 0, ans = 0;
        n = strlen(s);
        for (int i = 0; i < n; i++)
        {
            int id = idx(s[i]);
            while (now && !ch[now][id])
            {
                now = fail[now];
            }
            now = ch[now][id];
            int t = now;
            while (t && val[t] != -1)
            {
                ans += val[t];
                val[t] = -1;
                t = fail[t];
            }
        }
        return ans;
    }
} ac;

char buf[1000005];
int main()
{
    int t;
    int n;
    scanf("%d", &t);
    while (t--)
    {
        ac.init();
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%s", buf);
            ac.insert(buf);
        }
        ac.build();
        scanf("%s", buf);
        printf("%d\n", ac.query(buf));
    }
    return 0;
}
