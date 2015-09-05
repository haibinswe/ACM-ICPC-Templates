int wzf(int n, int m)
{
    if (n > m) swap(n, m);
    int k = m - n;
    int a = (k * (1.0 + sqrt(5.0)) / 2.0);
    if (a == n) return 0;
    else return 1;
}
//HDU 2177
int main()
{
    int a, b;
    while (~scanf("%d%d", &a, &b) && a | b)
    {
        if (wzf(a, b))
        {
            printf("1\n");
            if (a > b) swap(a, b);
            //第一种
            int k = b - a;
            double q = (1 + sqrt(5.0)) / 2;
            int ak = k * q;
            //特殊情况
            if (a == 0) printf("0 0\n");
            //同时减
            if (a >= ak) printf("%d %d\n", ak, ak + k);
            for (int i = 1; i <= b; i++)
            {
                //b减一点
                if (a == (int)(i * q) && b > a + i)
                    printf("%d %d\n", a, a + i);
                //b减很多
                else if (a == (int)(i * q) + i)
                    printf("%d %d\n", a - i, a);
                //a减一点
                else if (b == (int)(i * q) + i && b - i < a)
                    printf("%d %d\n", b - i, b);
            }
        }
        else printf("0\n");
    }
    return 0;
}
