//HDU 1556
#define N 100005
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
int sum[N << 2], add[N << 2];
void PushUp(int rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void PushDown(int rt, int m)
{
    if (add[rt])
    {
        add[rt << 1]   += add[rt];
        add[rt << 1 | 1] += add[rt];
        sum[rt << 1]   += add[rt] * (m - (m >> 1));
        sum[rt << 1 | 1] += add[rt] * (m >> 1);
        add[rt] = 0;
    }
}

void Update(int L, int R, int l, int r, int rt)
{
    if (L <= l && R >= r)
    {
        add[rt] += 1;
        sum[rt] += r - l + 1;
        return;
    }
    PushDown(rt, r - l + 1);
    int mid = (r + l) >> 1;
    if (L <= mid) Update(L, R, lson);
    if (R > mid ) Update(L, R, rson);
    PushUp(rt);
}

int Query(int L, int l, int r, int rt)
{
    int R = L;
    if (L <= l && R >= r) return sum[rt];
    PushDown(rt, r - l + 1);
    int mid = (r + l) >> 1;
    int res = 0;
    if (L <= mid) res += Query(L, lson);
    if (R > mid ) res += Query(L, rson);
    return res;
}
