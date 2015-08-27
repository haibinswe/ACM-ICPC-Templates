//不要忘记初始化bit[]数组
int N;
const int NV = 500005;
int bit[NV];
inline int lowbit(int x)
{
    return x & (-x);
}

void update(int x, int delta)
{
    for (int i = x; i <= N; i += lowbit(i))
    {
        bit[i] += delta;
    }
}

int query(int k)
{
    int ans = 0;
    for (int i = k; i > 0; i -= lowbit(i))
    {
        ans += bit[i];
    }
    return ans;
}

