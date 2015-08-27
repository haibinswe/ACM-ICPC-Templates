// 数据范围 a[x..(y-1)]， 为左闭右开区间。
int binarySearch(int *a, int x, int y, int v)
{
    while (x < y)
    {
        int mid = x + (y - x) / 2;
        if (v == a[mid])
            return mid;
        else if (v < a[mid])
            y = mid;
        else
            x = mid + 1;
    }
    return -1;
}

// 左闭右开区间 a[x..y-1]
//【求下界】寻找 a 的区间 [x, y) 中大于等于 v 的第一个数，
//使得 v 插入到 a 的对应位置以后，a 还是一个有序的数组。
int lowerBound(int *a, int x, int y, int v)
{
    while (x < y)
    {
        int mid = x + (y - x) / 2;
        /*
        v == a[mid]: 至少找到一个等于 v 的， 但前面可能还有。
        v < a[mid]: v 肯定不能在 mid 的后面。
        v > a[mid]: mid 和前面都不可以。
        */
        if (v <= a[mid]) y = mid;
        else x = mid + 1;
    }
    return x;
}
//【求上界】二分查找求下界的描述：寻找 a 的区间 [x, y) 中大于 v 的第一个数，
//使得 v 插入到 a 对应位置的前面一位之后， a 还是一个有序的数组。
int upperBound(int *a, int x, int y, int v)
{
    while (x < y)
    {
        int mid = x + (y - x) / 2;
        /*
        v == a[mid]: 答案肯定在后面， 因为不可能等于 v。
        v < a[mid]: mid 和后面都不可以。
        v > a[mid]: 应该在 mid 的后面。
        */
        if (v < a[mid]) y = mid;
        else x = mid + 1;
    }
    return y;
}
