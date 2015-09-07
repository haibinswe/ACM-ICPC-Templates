const int MAXN = 30;
const int mod = 1000000007;
long long C[MAXN][MAXN], B[MAXN];
void cinit()
{
    for (int i = 0; i < MAXN; i++)
    {
        C[i][0] = C[i][i] =  1;
        for (int j = 1; j <= i; j++)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
}

void binit()
{
    B[0] = B[1] = 1;
    for (int i = 2; i < MAXN; i++)
    {
        B[i] = 0;
        for (int j = 0; j <= i - 1; j++)
            B[i] = (B[i] + C[i - 1][j] * B[j] % mod) % mod;
    }
}
