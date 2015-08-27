//hdu 1823
#define NV 105
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
int sum[NV << 2][NV << 2], n = 1000;
void SubBuild(int t, int l, int r, int rt)
{
    sum[t][rt] = 0;
    if (l != r)
    {
        int mid = (l + r) >> 1;
        SubBuild(t, lson);
        SubBuild(t, rson);
    }
}

void Build(int l, int r, int rt)
{
    SubBuild(rt, 1, n, 1);
    if (l != r)
    {
        int mid = (l + r) >> 1;
        Build(lson);
        Build(rson);
    }
}

void SubUpdate(int y, int val, int t, int l, int r, int rt)
{
    if (l == r) sum[t][rt] = max(sum[t][rt], val);
    else
    {
        int mid = (l + r) >> 1;
        if (y <= mid) SubUpdate(y, val, t, lson);
        else SubUpdate(y, val, t, rson);
        sum[t][rt] = max(sum[t][rt << 1], sum[t][rt << 1 | 1]);
    }
}

void Update(int x, int y, int val, int l, int r, int rt)
{
    SubUpdate(y, val, rt, 1, n, 1);
    if (l != r)
    {
        int mid = (l + r) >> 1;
        if (x <= mid) Update(x, y, val, lson);
        else Update(x, y, val, rson);
    }
}

int SubQuery(int LY, int RY, int t, int l, int r, int rt)
{
    if (LY <= l && RY >= r) return sum[t][rt];
    int mid = (l + r) >> 1;
    int ans = -1;
    if (LY <= mid) ans = max(ans, SubQuery(LY, RY, t, lson));
    if (RY > mid ) ans = max(ans, SubQuery(LY, RY, t, rson));
    return ans;
}

int Query(int LX, int RX, int LY, int RY, int l, int r, int rt)
{
    if (LX <= l && RX >= r) return SubQuery(LY, RY, rt, 0, n, 1);
    int mid = (l + r) >> 1;
    int ans = -1;
    if (LX <= mid) ans = max(ans, Query(LX, RX, LY, RY, lson));
    if (RX > mid ) ans = max(ans, Query(LX, RX, LY, RY, rson));
    return ans;
}
