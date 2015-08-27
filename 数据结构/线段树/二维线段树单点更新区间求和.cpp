//poj 1195
#define N 1050
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
int sum[N * 3][N * 3], n;
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
    if (l == r) sum[t][rt] += val;
    else
    {
        int mid = (l + r) >> 1;
        if (y <= mid) SubUpdate(y, val, t, lson);
        else SubUpdate(y, val, t, rson);
        sum[t][rt] = sum[t][rt << 1] + sum[t][rt << 1 | 1];
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

long long SubQuery(int LY, int RY, int t, int l, int r, int rt)
{
    if (LY <= l && RY >= r) return sum[t][rt];
    int mid = (l + r) >> 1;
    long long ans = 0;
    if (LY <= mid) ans += SubQuery(LY, RY, t, lson);
    if (RY > mid ) ans += SubQuery(LY, RY, t, rson);
    return ans;
}

long long Query(int LX, int RX, int LY, int RY, int l, int r, int rt)
{
    if (LX <= l && RX >= r) return SubQuery(LY, RY, rt, 1, n, 1);
    int mid = (l + r) >> 1;
    long long ans = 0;
    if (LX <= mid) ans += Query(LX, RX, LY, RY, lson);
    if (RX > mid ) ans += Query(LX, RX, LY, RY, rson);
    return ans;
}

int main()
{
    int op;
    int a, b, c, d;
    while (~scanf("%d%d", &op, &n))
    {
        n++;
        Build(1, n, 1);
        while (scanf("%d", &op) && op != 3)
        {
            if (op == 1)
            {
                scanf("%d%d%d", &a, &b, &c);
                ++a, ++b;
                Update(a, b, c, 1, n, 1);
            }
            else
            {
                scanf("%d%d%d%d", &a, &b, &c, &d);
                ++a, ++b, ++c, ++d;
                printf("%I64d\n", Query(a, c, b, d, 1, n, 1));
            }
        }
    }
    return 0;
}
