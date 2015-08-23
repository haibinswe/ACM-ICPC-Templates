#include <string>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 1005;
//worth   volume
int w[MAXN], v[MAXN], dp[MAXN][MAXN];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int N, V;
        memset(dp, 0, sizeof(dp));
        scanf("%d%d", &N, &V);
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", w + i);
        }
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", v + i);
        }
        for (int i = 1; i <= N; i++)
        {
            for (int j = V; j >= 0; j--)
            {
                if (j < v[i]) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
            }
        }
        printf("%d\n", dp[N][V]);
    }
    return 0;
}
