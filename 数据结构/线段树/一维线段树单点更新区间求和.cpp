//单点更新区间求和
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int NV = 100005;
int sum[NV << 2];
void Build(int l, int r, int rt = 1)
{
    if (l == r)
    {
        sum[rt] = 0;
        return ;
    }
    int m = (l + r) >> 1;
    Build(lson);
    Build(rson);
    PushUp(rt);
}
void PushUp(int rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void Update(int L, int c, int l, int r, int rt = 1)
{
    if (L == l && l == r)
    {
        sum[rt] += c;
        return ;
    }
    int m = (l + r) >> 1;
    if (L <= m) Update(L, c, lson);
    else Update(L, c, rson);
    PushUp(rt);
}
int Query(int L, int R, int l, int r, int rt = 1)
{
    if (L <= l && r <= R) return sum[rt];
    int m = (l + r) >> 1;
    int ret = 0;
    if (L <= m) ret += Query(L, R, lson);
    if (m < R) ret += Query(L, R, rson);
    return ret;
}
