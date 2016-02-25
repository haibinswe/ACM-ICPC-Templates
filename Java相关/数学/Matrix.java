public static class Matrix {
    private final int N = 1005;
    private final long M = 1000000007;
    private int n, m;
    private long mat[][] = new long[N][N];
    private long quickpow(long A, long n) {
        if (n == 0) return 1;
        long ret = 1;
        while (n != 0) {
            if (n % 2 == 1) {
                ret = (A * ret) % M;
            }
            A = (A * A) % M;
            n >>= 1;
        }
        return ret;
    }
    private long inv(long a) {
        return quickpow(a, M - 2);
    }

    Matrix(int row, int col) {
        n = row;
        m = col;
    }
    Matrix(final Matrix x) {
        n = x.n;
        m = x.m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[i][j] = x.mat[i][j];
            }
        }
    }
    public void unit() {
        m = n;
        for (int i = 0; i < n; i++) {
            mat[i][i] = 1;
        }
    }
    public long numAt(int i, int j) {
        return mat[i][j];
    }
    public void setMat(int i, int j, int x) {
        mat[i][j] = x;
    }
    public Matrix add(final Matrix x) {
        Matrix t = new Matrix(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                t.mat[i][j] = (mat[i][j] + x.mat[i][j]) % M;
            }
        }
        return t;
    }
    public Matrix minus(final Matrix x) {
        Matrix t = new Matrix(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                t.mat[i][j] = (mat[i][j] - x.mat[i][j]) % M;
            }
        }
        return t;
    }
    public Matrix multiply(final Matrix x) {
        Matrix t = new Matrix(n, x.m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < x.m; k++) {
                    t.mat[i][k] = (t.mat[i][k] + (mat[i][j] * x.mat[j][k]) % M) % M;
                }
            }
        }
        return t;
    }
    public Matrix multiply(final long x) {
        Matrix t = new Matrix(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                t.mat[i][j] = mat[i][j] * x % M;
            }
        }
        return t;
    }
    public Matrix divide(final long x) {
        Matrix t = new Matrix(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                t.mat[i][j] = mat[i][j] * inv(x) % M;
            }
        }
        return t;
    }
    public Matrix transport() {
        Matrix t = new Matrix(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                t.mat[i][j] = mat[j][i];
            }
        }
        return t;
    }
    public Matrix quickpow(int x) {
        Matrix ret = new Matrix(n, m), tmp = this;
        ret.unit();
        if (x == 0) return ret;
        while (x != 0) {
            if (x % 2 == 1) ret = tmp.multiply(ret);
            tmp = tmp.multiply(tmp);
            x >>= 1;
        }
        return ret;
    }
}