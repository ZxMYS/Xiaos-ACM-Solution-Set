#include<stdio.h>
#include<stdlib.h>
int main(){
	int a=-59;
	int b=-85;
	int CF=0,ZF=0,OF=0,SF=0;
    asm __volatile__("\
		movl %4,%%eax;\
		movl %5,%%ebx;\
		cmpl %%eax,%%ebx;\
		setb %%dl;\
		movzbl %%dl,%%eax;\
		movl %%eax,%0;\
		sete %%dl;\
		movzbl %%dl,%%eax;\
		movl %%eax,%1;\
		sets %%dl;\
		movzbl %%dl,%%eax;\
		movl %%eax,%2;\
		setl %%dl;\
		movzbl %%dl,%%eax;\
		movl %%eax,%3;\
		\
		"
       :"=m"(CF),"=m"(ZF),"=m"(SF),"=m"(OF)
       :"r"(a), "r"(b)
       :"%edx","%eax","%ebx"
       );
    OF^=SF;
    printf("CF:%d,ZF:%d,SF:%d,OF:%d;\n",CF,ZF,SF,OF);
    system("pause");
	return 0;
}
