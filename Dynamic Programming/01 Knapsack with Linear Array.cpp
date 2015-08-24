#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

//worth   volume
int w[10005], v[10005], dp[10005];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int N, V;
        memset(dp, 0, sizeof(dp));
		//物品数量   最大容量
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
            for (int j = V; j >= v[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
            }
        }
        printf("%d\n", dp[V]);
    }
    return 0;
}
