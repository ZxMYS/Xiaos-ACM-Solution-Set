#include<stdio.h>

int main()
{
        int foo,bar;
        scanf("%d%d",&foo,&bar);
        __asm__ __volatile__("addl %%ebx,%%eax;\n"
                             :"=a"(foo)
                             :"a"(foo), "b"(bar)
                             );
        printf("%d\n", foo);
        return 0;
}
