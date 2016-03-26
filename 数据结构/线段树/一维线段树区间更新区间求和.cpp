//区间更新区间求和
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int NV = 100005;
int add[NV << 2], sum[NV << 2];
void PushUp(int rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void PushDown(int rt, int m)
{
    if (add[rt])
    {
        add[rt << 1] += add[rt];
        add[rt << 1 | 1] += add[rt];
        sum[rt << 1] += add[rt] * (m - (m >> 1));
        sum[rt << 1 | 1] += add[rt] * (m >> 1);
        add[rt] = 0;
    }
}
void Build(int l, int r, int rt = 1)
{
    add[rt] = 0;
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
void Update(int L, int R, int c, int l, int r, int rt = 1)
{
    if (L <= l && r <= R)
    {
        add[rt] += c;
        sum[rt] += c * (r - l + 1);
        return ;
    }
    PushDown(rt , r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) Update(L, R, c, lson);
    if (m < R) Update(L, R, c, rson);
    PushUp(rt);
}

int Query(int L, int R, int l, int r, int rt = 1)
{
    if (L <= l && r <= R) return sum[rt];
    PushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    int ret = 0;
    if (L <= m) ret += Query(L, R, lson);
    if (m < R) ret += Query(L, R, rson);
    return ret;
}
