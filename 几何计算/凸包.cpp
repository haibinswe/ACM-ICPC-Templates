struct Point
{
    double x, y;
    Point(double _x = 0.0, double _y = 0.0): x(_x), y(_y) {}
    Point operator + (const Point &b) const
    {
        return Point(x + b.x, y + b.y);
    }
    Point operator - (const Point &b) const
    {
        return Point(x - b.x, y - b.y);
    }
};

inline int sgn(const double &x)
{
    return x < -eps ? -1 : x > eps;
}

inline double det(const Point &a, const Point &b)
{
    return a.x * b.y - a.y * b.x;
}

bool cmp(const Point &a, const Point &b)//先比较x，后比较x均可
{
    return sgn(a.x - b.x) < 0 || (sgn(a.x - b.x) == 0 && sgn(a.y - b.y) < 0);
}

vector<Point> Graham(vector<Point> p)
{
    int n = p.size();
    sort(p.begin(), p.end(), cmp);
    p.erase(unique(p.begin(), p.end(), cmp), p.end());
    vector<Point> res(n + n + 5);
    int top = 0;
    for (int i = 0; i < n; i++)//扫描下凸壳
    {
        //<= 0则不含边界, < 0则含边界
        while (top > 1 && sgn(det(res[top - 1] - res[top - 2], p[i] - res[top - 2])) < 0) top--;
        res[top++] = p[i];
    }
    int k = top;
    for (int i = n - 2; i >= 0; i--)//扫描上凸壳
    {
        //<= 0则不含边界, < 0则含边界
        while (top > k && sgn(det(res[top - 1] - res[top - 2], p[i] - res[top - 2])) < 0) top--;
        res[top++] = p[i];
    }
    if (top > 1) top--; //最后一个点和第一个点一样, 可以不去掉, 某些计算时方便一些
    res.resize(top);
    return res;
}
