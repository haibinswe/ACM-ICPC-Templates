const int N = 1005;
// c1是保存各项质量砝码可以组合的数目
// c2是中间量，保存每一次的情况
int c1[N], c2[N];
int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i <= n; i++)
        {
            c1[i] = 1;
            c2[i] = 0;
        }
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                for (int k = 0; k + j <= n; k += i)
                    c2[j + k] += c1[j];
            }
            for (int j = 0; j <= n; j++)
            {
                c1[j] = c2[j];
                c2[j] = 0;
            }
        }
        printf("%d\n", c1[n]);
    }
    return 0;
}
