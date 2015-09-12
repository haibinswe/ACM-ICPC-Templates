//POJ 2728
const double INF = 1e12;
const int NV = 1010;
struct Village
{
    double x, y, h;
} village[NV];

struct Map
{
    double height, dis;
} g[NV][NV];

bool vis[NV];
int pre[NV];
double dis[NV];

double len(const Village &a, const Village &b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool prim(int v, double k, double &res)
{
    int p, s = v - 1;
    double m, h = 0, d = 0, sum = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < v; i++) dis[i] = INF;
    dis[0] = 0;
    vis[0] = 1;
    for (int i = 1; i < v; i++)
    {
        if (dis[i] > g[0][i].height - k * g[0][i].dis)
        {
            dis[i] = g[0][i].height - k * g[0][i].dis;
            pre[i] = 0;
        }
    }
    while (s--)
    {
        m = INF + 1;
        for (int i = 1; i < v; i++)
        {
            if (!vis[i] && m > dis[i])
            {
                m = dis[i];
                p = i;
            }
        }
        h += g[pre[p]][p].height;
        d += g[pre[p]][p].dis;
        sum += dis[p];
        vis[p] = 1;
        for (int i = 1; i < v; i++)
        {
            if (!vis[i] && dis[i] > g[p][i].height - k * g[p][i].dis)
            {
                dis[i] = g[p][i].height - k * g[p][i].dis;
                pre[i] = p;
            }
        }
    }
    res = h / d;
    return fabs(sum) < 1e-8;
}

double Dinkelbach(int v)
{
    double r = 1, res;
    while (!prim(v, r, res))
    {
        if (fabs(res - r) < 1e-8) break;
        r = res;
    }
    return res;
}

int main()
{
    int n;
    while (~scanf("%d", &n) && n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf%lf", &village[i].x, &village[i].y, &village[i].h);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                g[i][j].height = fabs(village[i].h - village[j].h);
                g[i][j].dis = len(village[i], village[j]);
                g[j][i] = g[i][j];
            }
        }
        printf("%.3f\n", Dinkelbach(n));
    }
    return 0;
}
