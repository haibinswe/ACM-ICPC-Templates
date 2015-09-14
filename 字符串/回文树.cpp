const int MAXN = 10005;
const int sigma = 26;
struct PalindromicTree
{
    char s[MAXN];
    int next[MAXN][sigma], fail[MAXN], cnt[MAXN], len[MAXN];
    int last, n, p;
    long long res;
    inline int newnode(int l)
    {
        cnt[p] = 0;
        len[p] = l;
        return p++;
    }
    inline void init()
    {
        newnode(0), newnode(-1); //two roots
        s[n] = -1;
        fail[0] = 1;
    }
    inline int FL(int x)
    {
        while (s[n - len[x] - 1] != s[n]) x = fail[x];
        return x;
    }
    void add(char c)
    {
        c -= 'a';
        s[++n] = c;
        int cur = FL(last);
        if (!next[cur][c])
        {
            int now = newnode(len[cur] + 2);
            fail[now] = next[FL(fail[cur])][c];
            next[cur][c] = now;
        }
        last = next[cur][c];
        ++cnt[last];
    }
    inline unsigned long long count()
    {
        unsigned long long pk = 0;
        for (int i = p - 1; ~i; --i)
        {
            cnt[fail[i]] += cnt[i];
            pk += ((unsigned long long)cnt[i]) * len[i];
        }
        return pk;
    }
} p;

char s[MAXN];
int main()
{
    scanf("%s", s);
    int len = strlen(s);
    p.init();
    for (int i = 0; i < len; i++)
    {
        p.add(s[i]);
    }
    printf("%llu\n", p.count());
    return 0;
}
