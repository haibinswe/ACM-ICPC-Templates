/**
 * prime[]:存储小范围的素数表
 * prime1[]:存储某一区间的素数表
 * pcount:小范围素数表中素数的个数
 * pcount1:某一区间的素数表中素数的个数
 * in[]、in1[]用来标记某一个数字是否为素数..
 */
const int N = 46500, MN = 1000010;
long long prime[N], prime1[MN];
long long pcount, p1count;
long long in[N], in1[MN];

void getsprime()  //快速筛小范围素数
{
    for (int i = 2; i < N; ++i)
    {
        in[i] = 1;
    }
    for (int i = 2; i < N; ++i)
    {
        if (!in[i])
        {
            continue;
        }
        for (int j = i * 2; j < N; j += i)
        {
            in[j] = 0;
        }
    }
    pcount = 0;
    for (int i = 2; i < N; ++i)
    {
        if (in[i])
        {
            prime[pcount++] = i;
        }
    }
}

void getlprime(long L, long U)
{
    if (U < N)   //假如区间的最大值就小于46500的话，那么之际用我们刚才求完的就好了
    {
        p1count = 0;
        for (int i = L; i <= U; ++i)
        {
            if (in[i])
            {
                prime1[p1count++] = i;
            }
        }
    }
    else     //筛大数区间内的素数的核心部分
    {
        long long k, size = U - L;
        for (long i = 0; i <= size; ++i)
        {
            in1[i] = 1;
        }
        for (long i = 0; i <= pcount && prime[i] * prime[i] <= U; ++i)
        {
            k = L / prime[i];
            if (k * prime[i] < L)
            {
                ++k;
            }
            if (k <= 1)
            {
                ++k;
            }
            while (k * prime[i] <= U)
            {
                in1[k * prime[i] - L] = 0;
                ++k;
            }
        }
        p1count = 0;
        for (long i = 0; i <= size; ++i)
        {
            if (in1[i])
            {
                prime1[p1count++] = i + L;
            }
        }
    }
}
