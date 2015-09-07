const int MAXN = 105;
void build(int l, int si, int sj, int sn, long long d[][MAXN])
{
    int n, i = 0, j = l / 2;
    for (n = 1; n <= l * l; n++)
    {
        d[i + si][j + sj] = n + sn;
        if (n % l == 0) i = (i == l - 1) ? 0 : (i + 1);
        else
        {
            i = (i) ? (i - 1) : (l - 1);
            j = (j == l - 1) ? 0 : (j + 1);
        }
    }
}

void magic_odd(int l, long long d[][MAXN])
{
    build(l, 0, 0, 0, d);
}

void magic_4k(int l, long long d[][MAXN])
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < l; j++)
        {
            d[i][j] = ((i % 4 == 0 || i % 4 == 3) && (j % 4 == 0 || j % 4 == 3)
                       || (i % 4 == 1 || i % 4 == 2) && (j % 4 == 1 || j % 4 == 2))
                       ? (l * l - (i * l + j)) : (i * l + j + 1);
        }
    }
}

void magic_other(int l, long long d[][MAXN])
{
    build(l / 2, 0, 0, 0, d);
    build(l / 2, l / 2, l / 2, l * l / 4, d);
    build(l / 2, 0, l / 2, l * l / 2, d);
    build(l / 2, l / 2, 0, l * l / 4 * 3, d);
    for (int i = 0; i < l / 2; i++)
    {
        for (int j = 0; j < l / 4; j++)
        {
            if (i != l / 4 || j)
                swap(d[i][j], d[i + l / 2][j]);
        }
    }
    swap(d[l / 4][l / 4], d[l / 4 + l / 2][l / 4]);
    for (int i = 0; i < l / 2; i++)
    {
        for (int j = l - l / 4 + 1; j < l; j++)
            swap(d[i][j], d[i + l / 2][j]);
    }
}

void Work(int l, long long d[][MAXN])
{
    if (l % 2) magic_odd(l, d);
    else if (l % 4 == 0) magic_4k(l, d);
    else magic_other(l, d);
}

void Print(int n, long long d[][MAXN])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%3I64d%c", d[i][j], " \n"[j == n - 1]);
    }
}
