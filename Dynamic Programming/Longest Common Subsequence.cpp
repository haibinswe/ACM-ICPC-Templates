const int N = 1005;
int c[N][N], b[N][N];
int LCSLength(char *x, char *y, int m, int n)
{
    int i, j;
    memset(c, 0, sizeof(c));
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 0;
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 1;
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = -1;
            }
        }
    }
    return c[m][n];
}

void PrintLCS(char *x, int i, int j)
{
    if (i == 0 || j == 0)
    {
        return;
    }
    if (b[i][j] == 0)
    {
        PrintLCS(x, i - 1, j - 1);
        printf("%c ", x[i - 1]);
    }
    else if (b[i][j] == 1)
    {
        PrintLCS(x, i - 1, j);
    }
    else
    {
        PrintLCS(x, i, j - 1);
    }
}

int main()
{
    char x[50] = {"ABCBDAB"};
    char y[50] = {"BDCABA"};
    int m, n;

    m = strlen(x);
    n = strlen(y);

    printf("%d\n", LCSLength(x, y, m, n));
    PrintLCS(x, m, n);

    return 0;
}
