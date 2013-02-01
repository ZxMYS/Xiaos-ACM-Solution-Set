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
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,l,tt;
typedef struct {int a,b;} sq;
sq sqs[6];
int cmp(const void* a, const void* b){
    int x=(*(sq*)a).a - (*(sq*)b).a;
    if(x)return x;
    return (*(sq*)a).b - (*(sq*)b).b;
}
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
LOOPB(i,0,6){
    scanf("%d%d",&m,&n);
    if(m>n){t=m;m=n;n=t;}
    sqs[i].a=n;sqs[i].b=m;
}
    
qsort(sqs,6,sizeof(sqs[0]),cmp);

for(i=0;i<5;i+=2){
    if(sqs[i].a!=sqs[i+1].a||sqs[i].b!=sqs[i+1].b)
    goto L1;
}
if(sqs[0].a==sqs[2].a){
    if(sqs[0].b==sqs[4].a){
        if(sqs[4].b==sqs[2].b)
            goto L2;
    }else if(sqs[0].b==sqs[4].b){
        if(sqs[4].a==sqs[2].b)
            goto L2;
    }
}
if(sqs[0].a==sqs[2].b){
    if(sqs[0].b==sqs[4].a){
        if(sqs[4].b==sqs[2].a)
            goto L2;
    }else if(sqs[0].b==sqs[4].b){
        if(sqs[4].a==sqs[2].a)
            goto L2;
    }
}
if(sqs[0].b==sqs[2].a){
    if(sqs[0].a==sqs[4].a){
        if(sqs[4].b==sqs[2].b)
            goto L2;
    }else if(sqs[0].a==sqs[4].b){
        if(sqs[4].a==sqs[2].b)
            goto L2;
        }
}
if(sqs[0].b==sqs[2].b){
    if(sqs[0].a==sqs[4].a){
        if(sqs[4].b==sqs[2].a)
            goto L2;
    }else if(sqs[0].a==sqs[4].b){
        if(sqs[4].a==sqs[2].a)
            goto L2;
    }
}

printf("IMPOSSIBLE\n");
return 0;
L2:
    printf("POSSIBLE\n");
    return 0;
L1:
    printf("IMPOSSIBLE\n");
    return 0;
}
