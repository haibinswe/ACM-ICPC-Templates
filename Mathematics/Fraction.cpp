#include <cstdio>

class Fraction
{
private:
    int num, den;
    int gcd(int x, int y)
    {
        int t;
        while (y)
        {
            t = x % y;
            x = y;
            y = t;
        }
        return  x;
    }
    int abs(int x)
    {
        return x > 0 ? x : -x;
    }
    void Format()
    {
        //将负号移动到分子上
        if (den < 0)
        {
            num = -num;
            den = -den;
        }
        int g = gcd(abs(num), den);
        num /= g;
        den /= g;
    }

public:
    Fraction(int n = 1, int d = 1): num(n), den(d)
    {
        Format();
    }
    Fraction operator + (const Fraction &x)
    {
        return Fraction(num * x.den + den * x.num, den * x.den);
    }
    Fraction operator - (const Fraction &x)
    {
        return Fraction(num * x.den - den * x.num, den * x.den);
    }
    Fraction operator * (const Fraction &x)
    {
        return Fraction(num * x.num, den * x.den);
    }
    Fraction operator / (const Fraction &x)
    {
        return Fraction(num * x.den, den * x.num);
    }
    friend bool operator < (const Fraction &x, const Fraction &y)
    {
        return x.num * y.den < x.den * y.num;
    }
    friend bool operator > (const Fraction &x, const Fraction &y)
    {
        return y < x;
    }
    friend bool operator == (const Fraction &x, const Fraction &y)
    {
        return x.num * y.den == x.den * y.num;
    }
    friend bool operator != (const Fraction &x, const Fraction &y)
    {
        return x.num * y.den != x.den * y.num;
    }
    void Print()
    {
        if (num == 0) printf("0\n");
        else if (abs(num) % den == 0) printf("%d\n", num / den);
        else printf("%d/%d\n", num, den);
    }
};

int main()
{
    int a, b, c, d;
    char ch;
    while (~scanf("%d/%d%c%d/%d", &a, &b, &ch, &c, &d))
    {
        Fraction A(a, b), B(c, d), C;
        if (ch == '+') C = A + B;
        else if (ch == '-') C= A - B;
        else if (ch = '*') C = A * B;
        else C = A / B;
        C.Print();
    }
    return 0;
}