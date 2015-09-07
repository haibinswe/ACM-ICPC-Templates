stack<int> number;
stack<char> op;
int g[50][50];
int num, index, flag;
char oper, c, str[1005];
int get_val(char str[])
{
    num = 0;
    if ((c <= '9' && c >= '0'))
    {
        while ((c <= '9' && c >= '0'))
        {
            flag = 0;
            num = num * 10 + c - '0';
            c = str[index++];
        }
        return 1;
    }
    else if ((c == '-' || c == '+') && flag)
    {
        int tmp = 1;
        flag = 0;
        if (c == '-') tmp = -tmp;
        while (((c = str[index++]) && (c <= '9' && c >= '0')))
            num = num * 10 + c - '0';
        num *= tmp;
        return 1;
    }
    else if (c == '(' || c == ')')
    {
        if (c == '(') flag = 1;
        if (c == ')') flag = 0;
        oper = c;
        return 0;
    }
    else if (c == 0) oper = ')';
    else oper = c;
    flag = 1;
    return 0;
}

int zero;
int Calculate(int a, int b, char tmp)
{
    if (tmp == '+') return a + b;
    if (tmp == '-') return a - b;
    if (tmp == '*') return a * b;
    if (b == 0)
    {
        zero = 1;
        return 1;
    }
    return a / b;
}

int Solve(char str[])
{
    index = 0;
    zero = 0;

    while (!number.empty()) number.pop();
    while (!op.empty()) op.pop();

    c = str[index++];
    int ans;
    op.push('(');
    while (!op.empty())
    {
        if (get_val(str)) number.push(num);
        else
        {
loop:
            char t1 = op.top();
            switch (g[t1][oper])
            {
            case 0:
                op.push(oper);
                c = str[index++];
                break;
            case 1:
                op.pop();
                if (op.empty()) break;
                c = str[index++];
                break;
            case 2:
                char tmp = op.top();
                op.pop();
                int b = number.top();
                number.pop();
                int a = number.top();
                number.pop();
                number.push(Calculate(a, b, tmp));
                goto loop;
                break;
            }
        }
    }
    ans = number.top();
    return ans;
}

void init()
{
    g['+']['+'] = 2;
    g['+']['-'] = 2;
    g['+']['*'] = 0;
    g['+']['/'] = 0;
    g['+']['('] = 0;
    g['+'][')'] = 2;
    g['-']['+'] = 2;
    g['-']['-'] = 2;
    g['-']['*'] = 0;
    g['-']['/'] = 0;
    g['-']['('] = 0;
    g['-'][')'] = 2;
    g['*']['+'] = 2;
    g['*']['-'] = 2;
    g['*']['*'] = 2;
    g['*']['/'] = 2;
    g['*']['('] = 0;
    g['*'][')'] = 2;
    g['/']['+'] = 2;
    g['/']['-'] = 2;
    g['/']['*'] = 2;
    g['/']['/'] = 2;
    g['/']['('] = 0;
    g['/'][')'] = 2;
    g['(']['+'] = 0;
    g['(']['-'] = 0;
    g['(']['*'] = 0;
    g['(']['/'] = 0;
    g['(']['('] = 0;
    g['('][')'] = 1;
    flag = 0;
}

int main()
{
    init();
    while (~scanf("%s", str))
    {
        int ans = Solve(str);
        printf("ans == %d\n", ans);
    }
    return 0;
}
