//备注：(1)左闭右开区间 (2)需要swap函数
void quickSort(int *start, int *end)
{
    if (start + 1 >= end) return;
    int *high = end, *low = start;
    //划分: 把比 *start 小的数据放到它的左侧，否则放右侧。
    while (low < high)
    {
        while (++low < end && *low <= *start);
        while (--high > start && *high >= *start);
        if (low < high) swap(*low, *high);
    }
    swap(*high, *start);
    quickSort(start, high);
    quickSort(low, end);
}
