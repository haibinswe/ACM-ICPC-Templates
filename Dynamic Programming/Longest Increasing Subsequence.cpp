//O(n^2)
const int N = 1005;
int dp[N];      //dp[i]记录到[0, i]数组的LIS
int lis = 1;    //LIS长度
int LIS(int * arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        dp[i] = 1;
    }
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            //如果要求非递减子序列只需将arr[j] < arr[i]改成<=
            //如果要求递减子序列只需改为>
            if (arr[j] < arr[i] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                if (dp[i] > lis)
                {
                    lis = dp[i];
                }
            }
        }
    }
    return lis;
}

//输出LIS
//存在疑问
void outputLIS(int * arr, int index)
{
    bool isLIS = 0;
    if (index < 0 || lis == 0)
    {
        return;
    }
    if (dp[index] == lis)
    {
        --lis;
        isLIS = 1;
    }
    outputLIS(arr, --index);
    if (isLIS)
    {
        printf("%d ", arr[index + 1]);
    }
}

//O(nlogn)
const int N = 50000;
int a[N], dp[N];
int LIS(int n)
{
    int len = 1;
    dp[1] = a[0]; //初始化：长度为1的LIS末尾为d[0]
    for (int i = 1; i < n; i++)
    {
        int pos = upper_bound(dp + 1, dp + len + 1, a[i]) - dp; //找到插入位置
        dp[pos] = a[i];
        if (len < pos) //按需要更新LIS长度
        {
            len = pos;
        }
    }
    return len;
}

int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", a + i);
        }
        printf("%d\n", LIS(n));
    }
    return 0;
}
