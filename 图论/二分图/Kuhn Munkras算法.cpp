const int MAX = 1024;
int n;                  // X 的大小
int weight[MAX][MAX];   // X 到 Y 的映射（权重）
int lx[MAX], ly[MAX];   // 标号
bool sx[MAX], sy[MAX];  // 是否被搜索过
int match[MAX];         // Y(i) 与 X(match[i]) 匹配

void init(int sz)
{
    // 根据实际情况，添加代码以初始化
    n = sz;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &weight[i][j]);
    }
}

bool path(int u)
{
    sx[u] = true;
    for (int v = 0; v < n; v++)
    {
        if (!sy[v] && lx[u] + ly[v] == weight[u][v])
        {
            sy[v] = true;
            if (match[v] == -1 || path(match[v]))
            {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}
// 参数 maxsum 为 true ，返回最大权匹配，否则最小权匹配
int Kuhn_Munkras(bool maxsum)
{
    if (!maxsum)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                weight[i][j] = -weight[i][j];
        }
    }
    // 初始化标号
    for (int i = 0; i < n; i++)
    {
        lx[i] = -0x1FFFFFFF;
        ly[i] = 0;
        for (int j = 0; j < n; j++)
            lx[i] = max(lx[i], weight[i][j]);
    }
    memset(match, -1, sizeof(match));
    for (int u = 0; u < n; u++)
    {
        while (true)
        {
            memset(sx, 0, sizeof(sx));
            memset(sy, 0, sizeof(sy));
            if (path(u)) break;
            // 修改标号
            int dx = 0x7FFFFFFF;
            for (int i = 0; i < n; i++)
            {
                if (sx[i])
                {
                    for (int j = 0; j < n; j++)
                        if (!sy[j]) dx = min(lx[i] + ly[j] - weight[i][j], dx);
                }
            }
            for (int i = 0; i < n; i++)
            {
                if (sx[i]) lx[i] -= dx;
                if (sy[i]) ly[i] += dx;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += weight[match[i]][i];
    }
    if (!maxsum)
    {
        sum = -sum;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                weight[i][j] = -weight[i][j];
        }
    }
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);
    init(n);
    int cost = Kuhn_Munkras(true);
    printf("%d\n", cost);
    for (int i = 0; i < n; i++)
    {
        printf("Y: %d -> X: %d\n", i, match[i]);
    }
    return 0;
}
