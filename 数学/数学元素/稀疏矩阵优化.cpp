//普通矩阵乘法
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
        for (int k = 0; k < x.m; k++)
            t.mat[i][k] = (t.mat[i][k] + (mat[i][j] * x.mat[j][k]) % M) % M;
    }
}
//稀疏矩阵乘法优化
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
        if (!mat[i][j]) continue;
        for (int k = 0; k < x.m; k++)
            t.mat[i][k] = (t.mat[i][k] + (mat[i][j] * x.mat[j][k]) % M) % M;
    }
}
