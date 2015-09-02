//二进制下的高斯消元
const int MAXN = 30;
int a[MAXN][MAXN], ans[MAXN], n;
bool l[MAXN];
int gauss(int a[][MAXN], bool l[], int ans[], const int& n)
{
    int res = 0, r = 0;
    for (int i = 0; i < n; i++) l[i] = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = r; j < n; j++)
        {
            if (a[j][i] > 0)
            {
                for (int k = i; k <= n; k++)
                    swap(a[j][k], a[r][k]);
                break;
            }
        }
        if (!a[r][i])
        {
            res++;
            continue;
        }
        for (int j = 0; j < n; j++)
        {
            if (j != r && a[j][i])
            {
                for (int k = i; k <= n; k++) a[j][k] ^= a[r][k];
            }
        }
        l[i] = true, r++;
    }
    for (int i = r; i < n; i++) if (a[i][n]) return -1;
    for (int i = 0; i < n; i++)
    {
        if (l[i])
        {
            for (int j = 0; j < n; j++)
                if (a[j][i] > 0) ans[i] = a[j][n];
        }
    }
    return res;
}

//枚举自由元得到最小的答案
int work(int a[][MAXN], int res, int n)
{
    int mn = inf;
    int tot = (1 << res);
    for (int i = 0; i < tot; i++)
    {
        int cnt = 0;
        for (int j = 0; j < res; j++)
        {
            if (i & (1 << j))
            {
                ans[n - j - 1] = 1;
                cnt++;
            }
            else ans[n - j - 1] = 0;
        }
        for (int j = n - res - 1; j >= 0; j--)
        {
            int tmp = a[j][n];
            for (int k = n - res; k < n; k++)
                if (a[j][k] && ans[k]) tmp ^= 1;
            ans[j] = tmp;
            if (tmp) cnt++;
        }
        mn = min(mn, cnt);
    }
    return mn;
}
