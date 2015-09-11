//POJ 2728
#define MAXV 1010
#define INF 1e12
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

struct Village
{
    double x, y, h;
} village[MAXV];

struct Map
{
    double height, dis;
} map[MAXV][MAXV];

bool vis[MAXV];
int pre[MAXV];
double dis[MAXV];

double len(const Village &a, const Village &b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool prim(int v, double k, double &res)
{
    int i, p, s = v - 1;
    double m, h = 0, d = 0, sum = 0;
    memset(vis, 0, sizeof(vis));
    for (i = 0; i < v; ++i) dis[i] = INF;
    dis[0] = 0;
    vis[0] = 1;
    for (i = 1; i < v; ++i)
    {
        if (dis[i] > map[0][i].height - k * map[0][i].dis)
        {
            dis[i] = map[0][i].height - k * map[0][i].dis;
            pre[i] = 0;
        }
    }
    while (s--)
    {
        m = INF + 1;
        for (i = 1; i < v; ++i)
        {
            if (!vis[i] && m > dis[i])
            {
                m = dis[i];
                p = i;
            }
        }
        h += map[pre[p]][p].height;
        d += map[pre[p]][p].dis;
        sum += dis[p];
        vis[p] = 1;
        for (i = 1; i < v; ++i)
        {
            if (!vis[i] && dis[i] > map[p][i].height - k * map[p][i].dis)
            {
                dis[i] = map[p][i].height - k * map[p][i].dis;
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
    int n, i, j;

    while (scanf("%d", &n) && n)
    {
        for (i = 0; i < n; ++i)
        {
            scanf("%lf %lf %lf", &village[i].x, &village[i].y, &village[i].h);
        }
        for (i = 0; i < n; ++i)
        {
            for (j = i + 1; j < n; ++j)
            {
                map[i][j].height = fabs(village[i].h - village[j].h);
                map[i][j].dis = len(village[i], village[j]);
                map[j][i] = map[i][j];
            }
        }

        printf("%.3lf\n", Dinkelbach(n));
    }
    return 0;
}
