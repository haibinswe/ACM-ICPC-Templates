#include <cstdio>
#include <vector>
using namespace std;

//S为原数组，temp为当前子集，result为所求子集集合，level为原数组中的元素下标亦为二叉树的层数
void subsets(vector<int> &S, vector<int> temp, vector<vector<int> > &result, int level = 0)
{
    //如果是叶子节点则加入到result中
    if (level == S.size())
    {
        result.push_back(temp);
        return;
    }
    //对于非叶子节点，不将当前元素加入到temp中
    subsets(S, temp, result, level + 1);
    //将元素加入到temp中
    temp.push_back(S[level]);
    subsets(S, temp, result, level + 1);
}

int main()
{
    vector<int> v, t;
    vector<vector<int> > r;
    int n, x;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            v.push_back(x);
        }
        subsets(v, t, r);
        for (vector<vector<int> >::iterator i = r.begin(); i != r.end(); i++)
        {
            for (vector<int>::iterator j = (*i).begin(); j != (*i).end(); j++)
                printf("%d ", *j);
            printf("\n");
        }
    }
    return 0;
}
