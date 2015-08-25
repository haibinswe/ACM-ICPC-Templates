/**
 * prime[]:�洢С��Χ��������
 * prime1[]:�洢ĳһ�����������
 * pcount:С��Χ�������������ĸ���
 * pcount1:ĳһ������������������ĸ���
 * in[]��in1[]�������ĳһ�������Ƿ�Ϊ����..
 */
const int N = 46500, MN = 1000010;
long long prime[N], prime1[MN];
long long pcount, p1count;
long long in[N], in1[MN];

void getsprime()  //����ɸС��Χ����
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
    if (U < N)   //������������ֵ��С��46500�Ļ�����ô֮�������Ǹղ�����ľͺ���
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
    else     //ɸ���������ڵ������ĺ��Ĳ���
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
