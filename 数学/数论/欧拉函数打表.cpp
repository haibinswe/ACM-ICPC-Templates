const int MAXN = 10005;
long long eular[MAXN];
void geteular()
{
    for (int i = 1; i < MAXN; i++)
    {
        eular[i] = i;
    }
    for (int i = 2; i < MAXN; i++)
    {
        if (eular[i] == i)
        {
            for (int j = i; j < MAXN; j += i)
                eular[j] = eular[j] / i * (i - 1);
        }
    }
}
