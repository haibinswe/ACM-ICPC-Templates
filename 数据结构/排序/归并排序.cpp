int temp[5000];
void mergeSort(int *start, int *end)
{
    if (start + 1 >= end) return;
    //划分阶段、递归
    int *mid = start + (end - start) / 2;
    mergeSort(start, mid);
    mergeSort(mid, end);
    //将mid两侧的两个有序表合并为一个有序表。
    int *p = start, *q = mid, *r = temp;
    while (p < mid || q < end)
    {
        if (q >= end || (p < mid && *p <= *q))
            *(r++) = *(p++);
        else
            *(r++) = *(q++);
    }
    for (p = start, r = temp; p < end; p++, r++) *p = *r;
}
