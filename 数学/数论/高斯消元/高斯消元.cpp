/*=====================================================
    复杂度：O(N^3)
    输入：a    方程组对应的矩阵
          n    未知数个数
          l    表示是否自由元
          ans  存储答案
    返回值：res = -1, 表示无解。
            res = 0, 表示有解。
            res > 0, 表示有无数解，res表示解空间的维数。
=======================================================*/
const int MAXN = 10000;
double a[MAXN][MAXN] = {0}, ans[MAXN] = {0};
bool l[MAXN];
int n;
int gauss(double a[][MAXN], bool l[], double ans[], const int& n)
{
    int res = 0, r = 0;
    for (int i = 0; i < n; i++) l[i] = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = r; j < n; j++)
        {
            if (fabs(a[j][i]) > eps)
            {
                for (int k = i; k <= n; k++)
                    swap(a[j][k], a[r][k]);
                break;
            }
        }
        if (fabs(a[r][i]) < eps)
        {
            res++;
            continue;
        }
        for (int j = 0; j < n; j++)
        {
            if (j != r && fabs(a[j][i]) > eps)
            {
                double tmp = a[j][i] / a[r][i];
                for (int k = i; k <= n; k++)
                    a[j][k] -= tmp * a[r][k];
            }
        }
        l[i] = true, r++;
    }
    for (int i = r; i < n; i++) if (fabs(a[i][n]) > eps) return -1;
    for (int i = 0; i < n; i++)
    {
        if (l[i])
        {
            for (int j = 0; j < n; j++)
                if (fabs(a[j][i]) > eps) ans[i] = a[j][n] / a[j][i];
        }
    }
    return res;
}
