const int NV = 1000005;
int a[NV], sub_a[NV], bit[NV];
inline int lowbit(int x)
{
    return x & (-x);
}

void update(int x)
{
    for (int i = x; i <= N; i += lowbit(i))
    {
        bit[i]++;
    }
}

int query(int k)
{
    int cnt = 0;
    for (int i = k; i > 0; i -= lowbit(i))
    {
        cnt += bit[i];
    }
    return cnt;
}

long long solve()
{
    long long ans = 0;
    memset(bit, 0, sizeof(bit));
    for (int i = 1; i <= N; i++)
    {
        sub_a[i] = a[i];
    }
    sort(sub_a + 1, sub_a + N + 1);
    int pos = unique(sub_a + 1, sub_a + N + 1) - sub_a - 1;
    for (int i = 1; i <= N; i++)
    {
        a[i] = lower_bound(sub_a + 1, sub_a + pos + 1, a[i]) - sub_a;
    }
    for (int i = 1; i <= N; i++)
    {
        update(a[i]);
        ans += i - query(a[i]);
    }
    return ans;
}
