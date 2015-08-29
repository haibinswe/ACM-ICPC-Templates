const int LEN = 1000005;
int NEXT[LEN];
char s[LEN], sub[LEN];
void getNEXT(char sub[], int NEXT[], int len2)
{
    int i = 0, j = -1;
    NEXT[0] = -1;
    while (i < len2)
    {
        if (j == -1 || sub[i] == sub[j])
            i++, j++, NEXT[i] = j;
        else j = NEXT[j];
    }
}

int KMP(char s[], char sub[], int len1, int len2, int NEXT[])
{
    int i = 0, j = 0;
    while (i < len1 && j < len2)
    {
        if (j == -1 || s[i] == sub[j])
            i++, j++;
        else j = NEXT[j];
    }
    if (j >= len2) return i - len2;
    else return -1;
}
