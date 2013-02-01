#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string>
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
#define oo (1<<29)
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,l,tt,cas,x1,x2,y1,y2;
char c;
bool ga[1002][1002];

inline int lowbit(int x){
    return x&(-x);
}

void change(int x,int y){
    while(y<=n){
        s=x;
        while(s<=n){
            ga[s][y]=!ga[s][y];
            s+=lowbit(s);
        }
        y+=lowbit(y);
    }
}

bool query(int x,int y){
    t=0;
    while(y>0){
        s=x;
        while(s>0){
            if(ga[s][y])t=!t;
            s-=lowbit(s);
        }
        y-=lowbit(y);
    }
    return t;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&cas);
while(cas--){
    scanf("%d%d\n",&n,&tt);
    memset(ga,0,sizeof(ga));
    while(tt--){
        scanf("%c",&c);
        if(c=='C'){
            scanf("%d%d%d%d\n",&x1,&y1,&x2,&y2);
            change(x1,y1);
            change(x1,y2+1);
            change(x2+1,y1);
            change(x2+1,y2+1);
        }else{
            scanf("%d%d\n",&x1,&y1);
            printf("%d\n",query(x1,y1));
        }
    }
    if(cas)putchar('\n');
}
}
