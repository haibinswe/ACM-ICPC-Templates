inline bool read(int &res)
{
    int c, flag = 0;
    c = getchar();
    if (c == EOF) return false;
    while (c == ' ' || c == '\n') c = getchar();
    flag = c == '-';
    res = c == '-' ? 0 : c - '0';
    while ((c = getchar()) >= '0' && c <= '9')
        res = res * 10 + c - '0';
    if (flag) res = -res;
    return true;
}

inline bool read(double &res)
{
    bool flag = 0;
    double _dec = 0.1;
    char ch = getchar();
    if (ch == EOF) return false;
    while (ch == ' ' || ch == '\n') ch = getchar();
    flag = ch == '-';
    res = ch == '-' ? 0.0 : ch - '0';
    while ((ch = getchar()) >= '0' && ch <= '9')
        res = res * 10 + ch - '0';
    if (ch == '.')
    {
        while ((ch = getchar()) >= '0' && ch <= '9')
        {
            res += _dec * (ch - '0');
            _dec *= 0.1;
        }
    }
    res = flag ? -res : res;
    return true;
}

inline void write(int res)
{
    if (res < 0)
    {
        res = -res;
        putchar('-');
    }
    if (res >= 10) write(res / 10);
    putchar(res % 10 + '0');
}
