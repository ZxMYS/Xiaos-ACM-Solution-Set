#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<assert.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string>
#include<set>
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
#define ABS(x) ((x)<0?-(x):(x))
#define PI 3.1415926535898
int i,j,k,a,m,n,s,t,l,tt,cas;
typedef unsigned int ul;
char str[50],ch;
ul mem[50],pc,accu;

inline ul get_high(const ul& a){
    return (a&(7<<5))>>5;
}

inline ul get_low(const ul& a){
    return a&31;
}

inline ul bit2int(char *a){
    ul ret=0;
    while(*a){
        ret<<=1;
        ret+=*a++=='1';
    }
    return ret;
}

inline void int2bit(int a){
    str[8]=0;
    ul t=1<<7;
    int i;
    LOOPB(i,0,8){
        str[i]=a&t?'1':'0';
        t>>=1;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
while(scanf("%c",&ch)!=EOF){
    ungetc(ch,stdin);
    accu=pc=0;
    LOOPB(i,0,32){
        scanf("%s\n",&str);
        mem[i]=bit2int(str);
    }
    while(1){
        pc=pc&((1<<5)-1);
        t=mem[pc];
        pc++;
        switch(get_high(t)){
            case 0:
                mem[get_low(t)]=accu;
                break;
            case 1:
                accu=mem[get_low(t)];
                accu&=((1<<8)-1);
                break;
            case 2:
                if(accu)break;
                pc=get_low(t);
                pc=pc&((1<<5)-1);
                break;
            case 3:
                break;
            case 4:
                accu--;
                accu&=255;
                break;
            case 5:
                accu++;
                accu&=255;
                break;
            case 6:
                pc=get_low(t);
                pc=pc&((1<<5)-1);
                break;
            case 7:
                goto L1;
        }
    }
    L1:
        int2bit(accu);
        printf("%s\n",str);
}
}
