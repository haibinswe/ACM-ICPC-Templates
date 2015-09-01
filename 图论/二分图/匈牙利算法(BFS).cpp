const int MAXN = 1005;
int nc, ns; //nc代表课程数 ns代表学生数
int lefts[MAXN], rights[MAXN];
int g[MAXN][MAXN];
int pre_left[MAXN], mark_right[MAXN];
int hungary()
{
    memset(lefts, -1, sizeof(lefts));
    memset(rights, -1, sizeof(rights));
    int ret = 0;
    for (int i = 1; i <= nc; i++)
    {
        queue<int> q;
        q.push(i);
        int ok = 0;
        memset(mark_right, 0, sizeof(mark_right));
        memset(pre_left, 0, sizeof(pre_left));
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v = 1; v <= ns; v++)
            {
                if (g[u][v] && !mark_right[v])
                {
                    mark_right[v] = 1;
                    if (rights[v] == -1)
                    {
                        ok = 1;
                        int sl = u, sr = v;
                        while (sl != 0)
                        {
                            int st = lefts[sl];
                            lefts[sl] = sr;
                            rights[sr] = sl;
                            sl = pre_left[sl];
                            sr = st;
                        }
                        break;
                    }
                    else
                    {
                        pre_left[rights[v]] = u;
                        q.push(rights[v]);
                    }
                }
            }
            if (ok) break;
        }
        if (ok) ret++;
    }
    return ret;
}
