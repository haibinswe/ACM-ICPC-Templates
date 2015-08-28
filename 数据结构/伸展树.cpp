#define MAXN 2000005
#define MAXL 100005
struct Splay_Tree
{
    struct Node
    {
        Node *c[2], *p;
        int value, size, Min, Max, lazy;
        bool rev;
    } *root, *null, *lb, *rb, S[MAXN];
    int scnt;
    Node * NewNode(int value, Node *p) //插入新节点
    {
        Node *e = S + (++scnt);
        e->value = value;
        e->size = 1;
        e->p = p;
        e->Min = value;
        //初始化成一个小的
        e->Max = -value;
        e->lazy = 0;
        e->rev = false;
        e->c[0] = e->c[1] = null;
        return e;
    }
    void Update(Node *p) //更新节点信息
    {
        if (p == null) return;
        p->size = p->c[0]->size + p->c[1]->size + 1;
        p->Min = min(p->value, min(p->c[0]->Min, p->c[1]->Min));
        p->Max = max(p->value, max(p->c[0]->Max, p->c[1]->Max));
    }
    void PushDown(Node *x) //更新标记
    {
        if (x == null) return;
        if (x->rev)
        {
            x->rev = false;
            Node *t = x->c[0];
            x->c[0] = x->c[1];
            x->c[1] = t;
            x->c[0]->rev = !x->c[0]->rev;
            x->c[1]->rev = !x->c[1]->rev;
        }
        if (x->lazy)
        {
            int w = x->lazy;
            x->value += w;
            x->Min += w;
            x->Max += w;
            x->c[0]->lazy += w;
            x->c[1]->lazy += w;
            x->lazy = 0;
        }
    }
    void Rotate(Node *x, int k) //左旋 k=0；右旋 k=1；
    {
        Node *y = x->p;
        PushDown(x->c[0]);
        PushDown(x->c[1]);
        PushDown(y->c[!k]);
        y->c[k] = x->c[!k];
        y->c[k]->p = y;
        x->p = y->p;
        if (y->p->c[0] == y) y->p->c[0] = x;
        else y->p->c[1] = x;
        y->p = x;
        x->c[!k] = y;
        Update(y);
        Update(x);
        if (root == y) root = x;
    }
    void Splay(Node *x, Node *y) //伸展
    {
        PushDown(x);
        while (x->p != y)
        {
            if (x->p->p == y)
            {
                if (x->p->c[0] == x) Rotate(x, 0);
                else Rotate(x, 1);
            }
            else if (x->p->p->c[0] == x->p)
            {
                if (x->p->c[0] == x) Rotate(x->p, 0), Rotate(x, 0);
                else Rotate(x, 1), Rotate(x, 0);
            }
            else
            {
                if (x->p->c[1] == x) Rotate(x->p, 1), Rotate(x, 1);
                else Rotate(x, 0), Rotate(x, 1);
            }
        }
        Update(x);
    }
    void Select(int k, Node *y)
    {
        Node *x = root;
        PushDown(x);
        while (k != x->c[0]->size + 1)
        {
            if (k <= x->c[0]->size) x = x->c[0];
            else
            {
                k -= x->c[0]->size + 1;
                x = x->c[1];
            }
            PushDown(x);
        }
        Splay(x, y);
    }
    void MakeTree(int l, int r, int C[], Node *p, int side)
    {
        if(l > r) return;
        int mid = (l + r) >> 1;
        Node *x;
        x = NewNode(C[mid], p);
        p->c[side] = x;
        MakeTree(l, mid - 1, C, x, 0);
        MakeTree(mid + 1, r, C, x, 1);
        Update(x);
    }
    void Insert(int pos, int cnt, int C[]) //在pos后插入长度为cnt的区间
    {
        Select(pos + 1, null);
        Select(pos + 2, root);
        MakeTree(1, cnt, C, root->c[1], 0);
        Splay(root->c[1]->c[0], null);
    }
    void Add(int pos, int cnt, int value) //对pos后长度为cnt的区间中的每个值都增加value
    {
        Select(pos, null);
        Select(pos + cnt + 1, root);
        root->c[1]->c[0]->lazy += value;
        Splay(root->c[1]->c[0], null);
    }
    void Delete(int pos, int cnt) //删除pos后长度为cnt的区间
    {
        Select(pos, null);
        Select(pos + cnt + 1, root);
        root->c[1]->c[0] = null;
        Splay(root->c[1], null);
    }
    void Reverse(int pos, int cnt) //旋转pos后长度为cnt的区间
    {
        Select(pos, null);
        Select(pos + cnt + 1, root);
        root->c[1]->c[0]->rev = !root->c[1]->c[0]->rev;
        Splay(root->c[1]->c[0], null);
    }
    void Revolve(int a, int b, int k) //将[a,b]区间向右旋转k步
    {
        int len = (b - a + 1), A, B, C;
        k = ((k % len) + len) % len;
        if (k == 0) return;
        A = a;
        B = b - k;
        C = b;                //转化成交换区间[A,B],[B+1,C];
        Node *p1, *p2, *p3, *p4;
        Select(A, null);
        p1 = root;      //A-1;
        Select(C + 2, null);
        p2 = root;      //C+1;
        Select(A + 1, null);
        p3 = root;      //A;
        Select(B + 1, null);
        p4 = root;      //B;

        Select(A, null);          //将A-1伸展成root
        Select(C + 2, p1);        //将C+1伸展到A-1的右边
        Select(B + 1, p2);        //将B伸展到C+1的左边
        Node *x;

        x = p4->c[1];             //把b的右子树切断，挂在a的左边
        p4->c[1] = null;

        p3->c[0] = x;
        Splay(p3, null);          //把a伸展为root,一路更新即可
    }
    int GetMin(int pos, int cnt) //获得pos后长度为cnt的区间的最小值
    {
        Select(pos, null);
        Select(pos + cnt + 1, root);
        PushDown(root->c[1]->c[0]);
        return root->c[1]->c[0]->Min;
    }
    //求最大值的时候树的初始化应该为-inf，用法同GetMin
    int GetMax(int pos, int cnt)
    {
        Select(pos, null);
        Select(pos + cnt + 1, root);
        PushDown(root->c[1]->c[0]);
        return root->c[1]->c[0]->Max;
    }
    void Index(int pos)
    {
        Select(pos + 1, null);
        printf("*%d\n", root->value);
    }
    void Print()  //打印区间
    {
        for (int i = 1; i < scnt - 1; i++)
            Index(i);
    }
    void Init()
    {
        scnt = -1;
        null = 0;
        null = NewNode(inf, 0);
        null->size = 0;
        lb = root = NewNode(inf, null);
        rb = root->c[1] = NewNode(inf, root);
        Update(root);
    }
} Splay;

int N, M, pos;
int C[MAXL], ans;
char s[20];
int main()
{
    int a, b, c, k;
    Splay.Init();
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &C[i]);
    Splay.Insert(0, N, C);

    scanf("%d", &M);
    while (M--)
    {
        scanf("%s", s);
        if (s[0] == 'A')
        {
            scanf("%d%d%d", &a, &b, &c);
            Splay.Add(a, b - a + 1, c);
        }
        else if (s[0] == 'R')
        {
            scanf("%d%d", &a, &b);
            if (s[3] == 'E') Splay.Reverse(a, b - a + 1);
            else
            {
                scanf("%d", &k);
                Splay.Revolve(a, b, k);
            }
        }
        else if (s[0] == 'I')
        {
            scanf("%d%d", &a, &C[1]);
            Splay.Insert(a, 1, C);
        }
        else if (s[0] == 'D')
        {
            scanf("%d", &a);
            Splay.Delete(a, 1);
        }
        else
        {
            scanf("%d%d", &a, &b);
            ans = Splay.GetMin(a, b - a + 1);
            printf("%d\n", ans);
        }
    }
    return 0;
}
