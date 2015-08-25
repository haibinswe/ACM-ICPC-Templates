#define lson l,m
#define rson m+1,r
const int NV = 100005;
const int NN = NV*25;
int sum[NN],ln[NN],rn[NN];
int tot,root[NV];
void PushUp(int k)
{
    sum[k]=sum[ln[k]]+sum[rn[k]];
}
int build(int l,int r)
{
    int k=++tot;
    if (l == r)
    {
        sum[k]=0;
        return k;
    }
    int m = (l + r) >> 1;
    ln[k]=build(lson);
    rn[k]=build(rson);
    PushUp(k);
    return k;
}
int update(int o,int L,int c,int l,int r)
{
    int k=++tot;
    sum[k]=sum[o];
    ln[k]=ln[o];
    rn[k]=rn[o];
    if (L == l && l == r)
    {
        sum[k]+=c;
        return k;
    }
    int m = (l + r) >> 1;
    if (L <= m) ln[k]=update(ln[o], L , c , lson);
    else rn[k]=update(rn[o], L , c , rson);
    PushUp(k);
    return k;
}
int query(int a,int b,int L,int l,int r)
{
    if (l==r) return l;
    int m = (l + r) >> 1;
    int tmp=sum[ln[b]]-sum[ln[a]];
    if (L <= tmp) return query(ln[a], ln[b], L , lson);
    return query(rn[a], rn[b], L-tmp , rson);
}
int discrete(int data[],int n,int dis[],int idx[])
{
    int sub[n+1];
    memcpy(sub,data,sizeof(sub));
    sort(sub+1,sub+n+1);
    int m=unique(sub+1,sub+n+1)-sub-1;
    for(int i=1; i<=n; i++)
    {
        dis[i]=lower_bound(sub+1,sub+m+1,data[i])-sub;
        idx[dis[i]]=data[i];
    }
    return m;
}
int a[NV],dis[NV],idx[NV];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    discrete(a,n,dis,idx);
    root[0]=build(1,n);
    for (int i=1; i<=n; i++)
        root[i]=update(root[i-1],dis[i],1,1,n);
    while(m--)
    {
        int aa,bb,k;
        scanf("%d%d%d",&aa,&bb,&k);
        printf("%d\n",idx[query(root[aa-1],root[bb],k,1,n)]);
    }
    return 0;
}
