// treap 模板，静态实现，带有内存回收
// 使用前需要重载 < 运算符
const int MAXN = 10005;
template<typename T>
class Treap
{
public:
    Treap()
    {
        srand((unsigned int)time(NULL));
        ch[0][0] = ch[0][1] = sz[0] = 0;
        fix[0] = -1;
        root = tot = top = 0;
    }
    ~Treap() {}
    void clear()
    {
        root = tot = top = 0;
    }
    int size()
    {
        return sz[root];
    }
    bool empty()
    {
        return !root;
    }
    void insert(const T &it)
    {
        insert(root, it);
    }
    void erase(const T &it)
    {
        erase(root, it);
    }
    bool find(const T &it)
    {
        return find(root, it);
    }
    const T &minItem()
    {
        return minMax(root, 0);
    }
    const T &maxItem()
    {
        return minMax(root, 1);
    }
    const T &select(int k)
    {
        return select(root, k);
    }
    int rank(const T &it)
    {
        return rank(root, it);
    }

private:
    T key[MAXN];
    int ch[MAXN][2], fix[MAXN], sz[MAXN], root, tot, stk[MAXN], top;
    void rotate(int &x, int d)
    {
        int y = ch[x][d ^ 1];
        ch[x][d ^ 1] = ch[y][d];
        ch[y][d] = x;
        sz[y] = sz[x];
        sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1;
        x = y;
    }
    void insert(int &x, const T &it)
    {
        if (!x)
        {
            key[x = top ? stk[top--] : ++tot] = it;
            ch[x][0] = ch[x][1] = 0;
            sz[x] = 1;
            fix[x] = abs(rand() * rand());
        }
        else
        {
            ++sz[x];
            insert(ch[x][key[x] < it], it);
            if (fix[x] < fix[ch[x][key[x] < it]])
                rotate(x, !(key[x] < it));
        }
    }
    void erase(int &x, const T &it)
    {
        bool d;
        if (!x) return;
        --sz[x];
        if (it < key[x] || key[x] < it)
            erase(ch[x][key[x] < it], it);
        else
        {
            if (!ch[x][0] || !ch[x][1])
            {
                stk[++top] = x;
                x = ch[x][!ch[x][0]];
            }
            else
            {
                rotate(x, d = fix[ch[x][1]] < fix[ch[x][0]]);
                erase(ch[x][d], it);
            }
        }
    }
    bool find(int x, const T &it)
    {
        if (!x || !(it < key[x] || key[x] < it)) return x;
        return find(ch[x][key[x] < it], it);
    }
    const T &minMax(int x, int d)
    {
        return ch[x][d] ? minMax(ch[x][d], d) : key[x];
    }
    const T &select(int x, int k)
    {
        if (!x || k == sz[ch[x][0]] + 1) return key[x];
        return select(ch[x][sz[ch[x][0]] + 1 < k],
                      sz[ch[x][0]] + 1 < k ? k - sz[ch[x][0]] - 1 : k);
    }
    int rank(int x, const T &it)
    {
        if (!x || !(it < key[x] || key[x] < it)) return sz[ch[x][0]] + 1;
        return rank(ch[x][key[x] < it], it)
                + (key[x] < it ? sz[ch[x][0]] + 1 : 0);
    }
};
