/*=====================================================
    在(long long 范围内，可以扩展为大数）
    复杂度：O(N^3)
    输入：a    方程组对应的矩阵
          n    未知数个数
          l    表示是否自由元
          ans  存储答案
    返回值：res = -1, 表示无解。
            res = 0, 表示有解。
            res > 0, 表示有无数解，res表示解空间的维数。
=======================================================*/
const int MAXN = 15;
long long a[MAXN][MAXN] = {0}, ans[MAXN] = {0};
bool l[MAXN];
int n;
int gauss(long long a[][MAXN], bool l[], long long ans[], const int& n)
{
    int res = 0, r = 0;
    for (int i = 0; i < n; i++) l[i] = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = r; j < n; j++)
        {
            if (a[j][i] != 0)
            {
                for (int k = i; k <= n; k++)
                    swap(a[j][k], a[r][k]);
                break;
            }
        }
        if (a[r][i] == 0)
        {
            res++;
            continue;
        }
        for (int j = 0; j < n; j++)
        {
            if (j != r && a[j][i] != 0)
            {
                if (a[j][i] < 0)
                {
                    for (int k = 0; k <= n; k++) a[j][k] *= -1;
                }
                //如果答案没有超long long,就别用，或者中间过程用 很耗时间！
                long long gcd = __gcd(a[r][i], a[j][i]);
                long long lcm = a[r][i] / gcd * a[j][i];
                long long jmul = lcm / a[j][i];
                long long imul = lcm / a[r][i];
                for (int k = 0; k <= n; k++)
                {
                    a[j][k] = a[j][k] * jmul - a[r][k] * imul;
                }
            }
        }
        l[i] = true, r++;
    }
    for (int i = r; i < n; i++) if (a[i][n] != 0) return -1;
    for (int i = 0; i < n; i++)
    {
        if (l[i])
        {
            for (int j = 0; j < n; j++)
                if (a[j][i] != 0) ans[i] = a[j][n] / a[j][i];
        }
    }
    return res;
}
