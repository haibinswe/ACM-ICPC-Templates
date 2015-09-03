const int N = 105;
const long long M = 1000000007;
class Matrix
{
private:
    int n, m;
    long long mat[N][N];
    long long quickpow(long long A, long long n)
    {
        if (n == 0) return 1;
        long long ret = 1;
        while (n)
        {
            if (n & 1) ret = (ret * A) % M;
            A = (A * A) % M;
            n >>= 1;
        }
        return ret;
    }
    long long inv(long long a)
    {
        return quickpow(a, M - 2);
    }

public:
    Matrix(int row = N, int col = N): n(row), m(col)
    {
        memset(mat, 0, sizeof(mat));
    }
    void Unit()
    {
        m = n;
        for (int i = 0; i < n; i++)
        {
            mat[i][i] = 1;
        }
    }
    long long * operator [] (int i)
    {
        return mat[i];
    }
    Matrix& operator = (const Matrix &x)
    {
        n = x.n, m = x.m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                mat[i][j] = x.mat[i][j];
        }
        return *this;
    }
    Matrix operator + (const Matrix &x)
    {
        Matrix t(n, m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                t.mat[i][j] = (mat[i][j] + x.mat[i][j] + M) % M;
        }
        return t;
    }
    Matrix operator - (const Matrix &x)
    {
        Matrix t(n, m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                t.mat[i][j] = (mat[i][j] - x.mat[i][j] + M) % M;
        }
        return t;
    }
    Matrix operator * (const Matrix &x)
    {
        Matrix t(n, x.m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int k = 0; k < x.m; k++)
                    t.mat[i][k] = (t.mat[i][k] + (mat[i][j] * x.mat[j][k]) % M) % M;
            }
        }
        return t;
    }
    Matrix operator * (const long long &x)
    {
        Matrix t(n, m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                t.mat[i][j] = mat[i][j] * x % M;
        }
        return t;
    }
    Matrix operator / (const long long &x)
    {
        Matrix t(n, m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                t.mat[i][j] = mat[i][j] * inv(x) % M;
        }
        return t;
    }
    Matrix operator ! ()
    {
        Matrix t(n, m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                t.mat[i][j] = mat[j][i];
        }
        return t;
    }
    //矩阵快速幂
    Matrix& operator ^ (int x)
    {
        Matrix ret(n, m), tmp = *this;
        ret.Unit();
        if (x == 0) return ret;
        while (x)
        {
            if (x & 1) ret = tmp * ret;
            tmp = tmp * tmp;
            x >>= 1;
        }
        return ret;
    }
    void Read()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                scanf("%I64d", &mat[i][j]);
        }
    }
    void Write()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                printf("%I64d%c", mat[i][j], " \n"[j == m - 1]);
        }
    }
};
