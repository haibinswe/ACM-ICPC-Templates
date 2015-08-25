inline void read(int &res)
{
    int c, flag = 0;
    c = getchar();
    flag = c == '-' ? true : false;
    res = c == '-' ? 0 : c - '0';
    while ((c = getchar()) >= '0' && c <= '9')
        res = res * 10 + c - '0';
    if (flag) res = -res;
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