const int N = 500000;
const int M = 26;
struct TrieTree
{
    struct TrieNode
    {
        int cnt;
        int node[M];
        TrieNode()
        {
            cnt = 0;
            memset(node, 0, sizeof(node));
        }
    } ch[N];
    int sz;
    TrieTree()
    {
        sz = 0;
    }
    void insert(char *s)
    {
        int c, u = 0, len = strlen(s);
        for (int i = 0; i < len; i++)
        {
            c = s[i] - 'a';
            if (ch[u].node[c] == 0)
            {
                ch[u].node[c] = ++sz;
                u = sz;
            }
            else u = ch[u].node[c];
            ch[u].cnt++;
        }
    }
    int query(char *s)
    {
        int c, u = 0, len = strlen(s);
        for (int i = 0; i < len; i++)
        {
            c = s[i] - 'a';
            if (ch[u].node[c] == 0) return 0;
            u = ch[u].node[c];
        }
        return ch[u].cnt;
    }
};
