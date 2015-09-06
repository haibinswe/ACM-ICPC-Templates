const double eps = 1e-8;
inline double sqr(const double &x)
{
    return x * x;
}
inline int sgn(const double &x)
{
    return x < -eps ? -1 : x > eps;
}
struct Point
{
    double x, y, z;
    Point() { }
    Point(double _x, double _y, double _z): x(_x), y(_y), z(_z) { }
    double operator * (const Point &b) const  //点积
    {
        return x * b.x + y * b.y + z * b.z;
    }
    Point operator ^ (const Point &b) const   //叉积
    {
        return Point(y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.x);
    }
    Point operator * (const double &b) const  //标量乘
    {
        return Point(x * b, y * b, z * b);
    }
    Point operator + (const Point &b) const   //向量加
    {
        return Point(x + b.x, y + b.y, z + b.z);
    }
    Point operator - (const Point &b) const   //向量减
    {
        return Point(x - b.x, y - b.y, z - b.z);
    }
    double norm()
    {
        return sqrt(sqr(x) + sqr(y) + sqr(z));
    }
};
struct Line
{
    Point a, b;
    Line() { }
    Line(const Point &_a, const Point &_b): a(_a), b(_b) { }
};
struct Plane
{
    Point a, b, c;
    Plane() { }
    Plane(const Point &_a, const Point &_b, const Point &_c): a(_a), b(_b), c(_c) { }
};
double dist(const Point &a, const Point &b)
{
    return (a - b).norm();
}
double dist2(const Point &a, const Point &b)
{
    return (a - b) * (a - b);
}
//平面法向量
Point pvec(const Plane &s)
{
    return (s.b - s.a) ^ (s.c - s.a);
}
//判定点是否在线段上，包括端点
bool point_on_seg(const Point &p, const Line &s)
{
    return sgn(((p - s.a) ^ (s.b - s.a)).norm()) == 0
           && (p.x - s.a.x) * (p.x - s.b.x) < eps
           && (p.y - s.a.y) * (p.y - s.b.y) < eps
           && (p.z - s.a.z) * (p.z - s.b.y) < eps;
}
//判断点在平面上
bool point_on_plane(const Point &p, const Plane &s)
{
    return sgn((p - s.a) * pvec(s)) == 0;
}
//判定点是否在空间三角形上，包括边界，三点共线无意义
bool point_in_triangle(const Point &p, const Plane &s)
{
    return sgn(((s.a - s.b) ^ (s.a - s.c)).norm()
               - ((p - s.a) ^ (p - s.b)).norm()
               - ((p - s.b) ^ (p - s.c)).norm()
               - ((p - s.c) ^ (p - s.a)).norm()) != 0;
}
//判定点是否在空间三角形上，不包括边界，三点共线无意义
int point_in_triangle2(const Point &p, const Plane &s)
{
    return point_in_triangle(p, s)
           && ((p - s.a) ^ (p - s.b)).norm() > eps
           && ((p - s.b) ^ (p - s.c)).norm() > eps
           && ((p - s.c) ^ (p - s.a)).norm() > eps;
}
//判定两点在线段同侧，点在线段上返回0，不共面无意义
bool same_side(const Point &p1, const Point &p2, const Line &l)
{
    return ((l.a - l.b) ^ (p1 - l.b)) * ((l.a - l.b) ^ (p2 - l.b)) > eps;
}
//判定两点在线段异侧，点在平面上返回0
bool opposite_side(const Point &p1, const Point &p2, const Line &l)
{
    return ((l.a - l.b) ^ (p1 - l.b)) * ((l.a - l.b) ^ (p2 - l.b)) < -eps;
}
//判定两点在平面同侧，点在平面上返回0
bool same_side(const Point &p1, const Point &p2, const Plane &s)
{
    return (pvec(s) * (p1 - s.a)) * (pvec(s) * (p2 - s.a)) > eps;
}
//判定两点在平面异侧，点在平面上返回0
bool opposite_side(const Point &p1, const Point &p2, const Plane &s)
{
    return (pvec(s) * (p1 - s.a)) * (pvec(s) * (p2 - s.a)) < -eps;
}
//判断直线平行
bool parallel(const Line &u, const Line &v)
{
    return sgn(((u.b - u.a) ^ (v.b - v.a)).norm()) == 0;
}
//判定两线段相交，不包括端点和部分重合
bool seg_seg_inter(const Line &u, const Line &v)
{
    return point_on_plane(u.a, Plane(u.b, v.a, v.b))
           && opposite_side(u.a, u.b, v)
           && opposite_side(v.a, v.b, u);
}
//判定线段与空间三角形相交，包括交于边界和（部分）包含
int seg_triangle_inter(const Line &l, const Plane &s)
{
    return !same_side(l.a, l.b, s)
           && !same_side(s.a, s.b, Plane(l.a, l.b, s.c))
           && !same_side(s.b, s.c, Plane(l.a, l.b, s.a))
           && !same_side(s.c, s.a, Plane(l.a, l.b, s.b));
}
//判定线段与空间三角形相交，不包括交于边界和（部分）包含
int seg_triangle_inter2(const Line &l, const Plane &s)
{
    return opposite_side(l.a, l.b, s)
           && opposite_side(s.a, s.b, Plane(l.a, l.b, s.c))
           && opposite_side(s.b, s.c, Plane(l.a, l.b, s.a))
           && opposite_side(s.c, s.a, Plane(l.a, l.b, s.b));
}
//面面平行
bool parallel(const Plane &s1, const Plane &s2)
{
    return sgn((pvec(s1) ^ pvec(s2)).norm()) == 0;
}
//判断直线垂直
bool vertical(const Line &u, const Line &v)
{
    return sgn((u.b - u.a) * (v.b - v.a)) == 0;
}
//面面垂直
bool vertical(const Plane &s1, const Plane &s2)
{
    return sgn(pvec(s1) * pvec(s2)) == 0;
}
//判断两直线的位置关系
int line_to_line(const Line &u, const Line &v)
{
    Plane s1(u.a, u.b, v.a), s2(u.a, u.b, v.b);
    if (sgn((pvec(s1) ^ pvec(s2)).norm())) return -1;//异面
    else if(parallel(u, v)) return 0;//平行
    else return 1;//相交
}
//直线与平面关系
int line_to_plane(const Line &u, const Plane &s)
{
    if (sgn(pvec(s) * (u.b - u.a)) == 0)
    {
        if (point_on_plane(u.a, s)) return -1;//直线在平面上
        else return 0;//直线平行于平面
    }
    else return 1;//线面相交
}
//线面求交
Point line_plane_intersection(const Line &u, const Plane &s)
{
    Point ret = pvec(s), der = u.b - u.a;
    double t = ret * (s.a - u.a) / (ret * (u.b - u.a));
    return u.a + der * t;
}
//线线求交
Point line_interseciton(const Line &u, const Line &v)
{
    Point ret = u.a, v1 = (u.a - v.a) ^ (v.b - v.a), v2 = (u.b - u.a) ^ (v.b - v.a);
    double t = v1.norm() / v2.norm() * ((v1 * v2) > 0 ? -1 : 1);
    return ret + ((u.b - u.a) * t);
}
//面面求交
Line plane_intersection(const Plane &u, const Plane &v)
{
    Line ret;
    ret.a = (line_to_plane(Line(v.a, v.b), u) == 0)
            ? line_plane_intersection(Line(v.b, v.c), u)
            : line_plane_intersection(Line(v.a, v.b), u);
    ret.b = (line_to_plane(Line(v.c, v.a), u) == 0)
            ? line_plane_intersection(Line(v.b, v.c), u)
            : line_plane_intersection(Line(v.a, v.c), u);
    return ret;
}
//点线距离
double dist_point_to_line(const Point &p, const Line &u)
{
    return ((p - u.a) ^ (u.b - u.a)).norm() / dist(u.a, u.b);
}
//点面距离
double dist_point_to_plane(const Point &p, const Plane &s)
{
    Point pv = pvec(s);
    return fabs(pv * (p - s.a)) / pv.norm();
}
//线线距离
double dist_line_to_line(const Line &u, const Line &v)
{
    Point p = (u.a - u.b) ^ (v.a - v.b);
    return fabs((u.a - v.a) * p) / p.norm();
}
//点线垂足
Point vertical_foot(const Point &p, const Line &u)
{
    double t = (p - u.a) * (u.b - u.a) / dist2(u.a, u.b);
    Point ret = u.a;
    return ret + ((u.b - u.a) * t);
}
//已知四面体六边求体积
double volume(double a, double b, double c, double d, double e, double f)
{
    double a2 = a * a, b2 = b * b, c2 = c * c, d2 = d * d, e2 = e * e, f2 = f * f;
    double tr1 = acos((c2 + b2 - f2) / (2.0 * b * c));
    double tr2 = acos((a2 + c2 - e2) / (2.0 * a * c));
    double tr3 = acos((a2 + b2 - d2) / (2.0 * a * b));
    double tr4 = (tr1 + tr2 + tr3) / 2.0;
    double temp = sqrt(sin(tr4) * sin(tr4 - tr1) * sin(tr4 - tr2) * sin(tr4 - tr3));
    return a * b * c * temp / 3.0;
}
//四面体体积
double volume(const Point &a, const Point &b, const Point &c, const Point &d)
{
    //abc面方向与d一致时为正
    return fabs(((b - a) ^ (c - a)) * (d - a)) / 6.0;
}
