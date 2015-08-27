int N;
long long bit[130][130][130] = {};
inline int lowbit(int x)
{
    return x & (-x);
}

void update(int x, int y, int z, long long v)
{
    for (int i = x; i <= N; i += lowbit(i))
    {
        for (int j = y; j <= N; j += lowbit(j))
        {
            for (int k = z; k <= N; k += lowbit(k))
            {
                bit[i][j][k] += v;
            }
        }
    }
}

long long query(int x, int y, int z)
{
    long long s = 0;
    for (int i = x; i > 0; i -= lowbit(i))
    {
        for (int j = y; j > 0; j -= lowbit(j))
        {
            for (int k = z; k > 0; k -= lowbit(k))
            {
                s += bit[i][j][k];
            }
        }
    }
    return s;
}

long long sum(int x, int y, int z, int xx, int yy, int zz)
{
    x--, y--, z--;
    return query(xx, yy, zz)
           - query(x, yy, zz) - query(xx, y, zz) - query(xx, yy, z)
           + query(x, y, zz) + query(xx, y, z) + query(x, yy, z)
           - query(x, y, z);
}
