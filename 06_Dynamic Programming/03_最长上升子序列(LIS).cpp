//O(n^2)
const int N = 1005;
int dp[N];      //dp[i]��¼��[0, i]�����LIS
int lis = 1;    //LIS����
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
            //���Ҫ��ǵݼ�������ֻ�轫arr[j] < arr[i]�ĳ�<=
            //���Ҫ��ݼ�������ֻ���Ϊ>
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

//���LIS
//��������
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
    dp[1] = a[0]; //��ʼ��������Ϊ1��LISĩβΪd[0]
    for (int i = 1; i < n; i++)
    {
        int pos = upper_bound(dp + 1, dp + len + 1, a[i]) - dp; //�ҵ�����λ��
        dp[pos] = a[i];
        if (len < pos) //����Ҫ����LIS����
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
