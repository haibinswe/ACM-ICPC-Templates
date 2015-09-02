void print(int index[], int arr[], int m)
{
    for (int i = 0; i < m; i++)
        printf("%3d", arr[index[i]]);
    printf("\n");
}

void combination(int n, int m, int index[], int arr[], int level = 0)
{
    int src, sink;
    if (level == 0) src = 0;
    else src = index[level - 1] + 1;
    sink = n - m + level;
    for (int i = src; i <= sink; i++)
    {
        index[level] = i;
        if (level == m - 1) print(index, arr, m);
        else combination(n, m, index, arr, level + 1);
    }
}
