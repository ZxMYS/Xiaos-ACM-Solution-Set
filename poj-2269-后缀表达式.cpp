#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<map>
#include<queue>
#include<list>
#include<sstream>
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define PI 3.1415926535898
const int oo=1<<27;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,st1,s,t,p,nt,st,num[500],stack[500];
char str[500];
inline int readgr(){
    int i=0;
    while(str[p]!='}')
        i|=(1<<(str[p++]-'A'));
    //p++;
    return i;
}

inline int exp(){
    while(str[p]){
        if(str[p]=='{'){
            p++;
            st1=readgr();
            num[nt++]=st1;
        }
        else if(str[p]=='(')
            stack[st++]='(';
        else if(str[p]==')'){
            while(stack[st-1]!='('&&st>0)
                num[nt++]=oo+stack[st---1];
            st--;
        }else if(str[p]=='*'){
            while(stack[st-1]=='*'&&st>0)
                num[nt++]=oo+stack[st---1];
            stack[st++]='*';
        }else{
            while(st>0&&stack[st-1]!='(')
                num[nt++]=oo+stack[st---1];
            stack[st++]=str[p];
        }
        p++;
    }
    while(st>0)
            num[nt++]=oo+stack[st---1];
}

inline int cal(){
    while(p<nt){
        if(num[p]<oo)
            stack[st++]=num[p];
        else{
            num[p]-=oo;
            if(num[p]=='*')
                stack[st-2]=stack[st-1]&stack[st-2];
            else if(num[p]=='+')
                stack[st-2]=stack[st-1]|stack[st-2];
            else if(num[p]=='-')
                stack[st-2]=(~stack[st-1])&stack[st-2];
            st--;
        }
        p++;
    }
    return stack[0];
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
while(scanf("%s",&str)!=EOF){
    p=0;
    nt=st=0;
    exp();
    //LOOPB(i,0,nt)
    //    printf("%d ",num[i]);
    //putchar('\n');
    p=0;st=0;
    st1=cal();
    j=1;
    putchar('{');
    LOOPB(i,0,26){
        if((st1&j)>0)printf("%c",'A'+i);
        j<<=1;
    }
    putchar('}');
    putchar('\n');
}
}
