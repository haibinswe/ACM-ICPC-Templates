int bash(int n, int m)
{
    if (n % (m + 1) != 0) return 1;
    else return 0;
}
//HDU 2149
int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        if (bash(n, m))
        {
            if (n > m) printf("%d\n", n % (m + 1));
            else
            {
                for (int i = n; i <= m; i++)
                    printf("%d%c", i, " \n"[i == m]);
            }
        }
        else printf("none\n");
    }
    return 0;
}
