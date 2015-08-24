#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int NV = 100005;
long long add[NV<<2],sum[NV<<2];
void PushUp(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void PushDown(int rt,int m)
{
    if (add[rt])
    {
        add[rt<<1] += add[rt];
        add[rt<<1|1] += add[rt];
        sum[rt<<1] += add[rt] * (m - (m >> 1));
        sum[rt<<1|1] += add[rt] * (m >> 1);
        add[rt] = 0;
    }
}
void build(int l,int r,int rt=1)
{
    add[rt] = 0;
    if (l == r)
    {
        scanf("%lld",&sum[rt]);
        return ;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUp(rt);
}
void update(int L,int R,long long c,int l,int r,int rt=1)
{
    if (L <= l && r <= R)
    {
        add[rt] += c;
        sum[rt] += c * (r - l + 1);
        return ;
    }
    PushDown(rt , r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update(L , R , c , lson);
    if (m < R) update(L , R , c , rson);
    PushUp(rt);
}
long long query(int L,int R,int l,int r,int rt=1)
{
    if (L <= l && r <= R)
    {
        return sum[rt];
    }
    PushDown(rt , r - l + 1);
    int m = (l + r) >> 1;
    long long ret = 0;
    if (L <= m) ret += query(L , R , lson);
    if (m < R) ret += query(L , R , rson);
    return ret;
}
int main()
{
    int n,q;
    cin>>n>>q;
    build(1,n);
    while(q--)
    {
        char s[5];
        int l,r;
        scanf("%s%d%d",s,&l,&r);
        if (s[0]=='Q')
            printf("%lld\n",query(l,r,1,n));
        else
        {
            long long c;
            scanf("%lld",&c);
            update(l,r,c,1,n);
        }
    }
    return 0;
}
