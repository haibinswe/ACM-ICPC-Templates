//ǿ��O2�Ż�
#pragma GCC optimize(2)

//G++(MinGW32)��ջ
//д��main()��������ǰ��
int SIZE_OF_STACK = 256 << 20; // 256MB
char *p = (char*)malloc(SIZE_OF_STACK) + SIZE_OF_STACK;
__asm__("movl %0, %%esp\n" :: "r"(p));

//G++(64λlinux)��ջ
//ֻ�ڻᱬջ�ĺ���ǰ��ʹ�û���������ȫ
//��Ҫע�����ʹ�þֲ��������溯������ֵ
long rsp;
int main()
{
    int SIZE_OF_STACK = 256 << 20; // 256MB
    char *p = (char*)malloc(SIZE_OF_STACK) + SIZE_OF_STACK;
    __asm__("movq %%rsp, %0" :: "m"(rsp));
    __asm__("movq %0, %%rsp" :: "r"(p));

    //������

    __asm__("movq %0, %%rsp\n" :: "m"(rsp));
    return 0;
}

//C++��ջ
#pragma comment(linker, "/STACK:102400000,102400000")