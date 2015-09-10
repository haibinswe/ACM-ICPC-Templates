const int MAXN = 1000005;
char str[MAXN << 1], s[MAXN];
int p[MAXN << 1], n;
void Manacher()
{
    int mx = 0, id;
    for (int i = n; str[i] != 0; i++)
        str[i] = 0;
    for (int i = 1; i < n; i++)
    {
        if (mx > i) p[i] = min(p[2 * id - i], p[id] + id - i);
        else p[i] = 1;
        for (; str[i + p[i]] == str[i - p[i]]; p[i]++);
        if (p[i] + i > mx)
        {
            mx = p[i] + i;
            id = i;
        }
    }
}

void init()
{
    str[0] = '$';
    str[1] = '#';
    for (int i = 0; i < n; i++)
    {
        str[i * 2 + 2] = s[i];
        str[i * 2 + 3] = '#';
    }
    n = n * 2 + 2;
    s[n] = 0;
}

int main()
{
    int cas = 1;
    while (~scanf("%s", s) && s[0] != 'E')
    {
        n = strlen(s);
        init();
        Manacher();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, p[i]);
        }
        printf("Case %d: %d\n", cas++, ans - 1);
    }
    return 0;
}
