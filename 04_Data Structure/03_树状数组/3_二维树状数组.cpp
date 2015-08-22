int N;
int c[2005][2005];
inline int lowbit(int x)
{
    return x & (-x);
}

void update(int x, int y, int v)
{
    for (int i = x; i <= N; i += lowbit(i))
    {
        for (int j = y; j <= N; j += lowbit(j))
        {
            c[i][j] += v;
        }
    }
}

int query(int x, int y)
{
    int s = 0;
    for (int i = x; i > 0; i -= lowbit(i))
    {
        for (int j = y; j > 0; j -= lowbit(j))
        {
            s += c[i][j];
        }
    }
    return s;
}

int sum(int x, int y, int xx, int yy)
{
    x--, y--;
    return query(xx, yy) - query(xx, y) - query(x, yy) + query(x, y);
}
