// 注意：如果想改成最小值堆，只需调换有(*)标记的代码中的不等号的方向。
const int N = 1000;
int heap[N], n;
inline int parent(int r)
{
    return (r - 1) / 2;
}
inline int leftChild(int r)
{
    return r * 2 + 1;
}
inline int rightChild(int r)
{
    return r * 2 + 2;
}
inline bool isLeaf(int r)
{
    return r >= n / 2;
}
void insert(int value)
{
    int curr = n++;
    heap[curr] = value;
    while (curr != 0 and heap[curr] > heap[parent(curr)]) // (*)
    {
        swap(heap[curr], heap[parent(curr)]);
        curr = parent(curr);
    }
}
void siftDown(int pos) // 使元素往下“ 拱”。 你不必手动调用此函数。
{
    while (not isLeaf(pos))
    {
        int i = leftChild(pos), j = rightChild(pos);
        if (j < n and heap[i] < heap[j]) i = j; // (*) 只改第二个不等号
        if (heap[i] <= heap[pos]) return; // (*)
        swap(heap[i], heap[pos]);
        pos = i;
    }
}
// 建堆。注意：在调用此函数之前，先初始化heap[]和n
void buildHeap()
{
    for (int i = n / 2 - 1; i >= 0; i--) siftDown(i);
}
int removeMax()
{
    if (n == 0) return 0;
    n--;
    swap(heap[0], heap[n]);
    if (n != 0) siftDown(0);
    return heap[n];
}
int removeItem(int pos)
{
    n--;
    swap(heap[pos], heap[n]);
    while (pos != 0 and heap[pos] > heap[parent(pos)]) // (*)
        swap(heap[pos], heap[parent(pos)]);
    siftDown(pos);
    return heap[n];
}
int getMax()
{
    return heap[0];
}
