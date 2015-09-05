//POJ 3301
int n, t;
struct Point
{
    int x, y;
} p[35];

void init()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &p[i].x, &p[i].y);
    }
}

double calc(double thta)
{
    double ax = 1e100, ay = 1e100, bx = -1e100, by = -1e100, x, y;
    //角度旋转
    for (int i = 1; i <= n; i++)
    {
        x = cos(thta) * p[i].x + sin(thta) * p[i].y;
        y = -sin(thta) * p[i].x + cos(thta) * p[i].y;
        if (x < ax) ax = x;
        if (x > bx) bx = x;
        if (y < ay) ay = y;
        if (y > by) by = y;
    }
    return max(bx - ax, by - ay);
}

void solve()
{
    double delta, angle, dd, mini, now, na, ans = 1e100;
    for (int i = 0; i <= 10; i++)
    {
        angle = 2.0 * PI * i / 10.0;
        delta = 2.0 * PI;
        na = 1e100;
        while (delta > eps)
        {
            mini = 1e100;
            if (angle + delta < 2.0 * PI && (now = calc(angle + delta)) < mini)
                mini = now, dd = delta;
            if (angle - delta > 0 && (now = calc(angle - delta)) < mini)
                mini = now, dd = -delta;
            if (mini < na)
                na = mini, angle += dd;
            delta *= 0.7;
        }
        ans = min(ans, na);
    }
    printf("%.2f\n", ans * ans);
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        init();
        solve();
    }
    return 0;
}
