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
int i,j,k,a,m,n,s,t,l,f=0,x=0; //tt= -1:_ 0:- 1:^
double price[20000],sum1=0,sum2=0,av1,av2;
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d%d%d",&m,&n,&k);
LOOPB(i,0,k){
    scanf("%lf",&price[i]);
}
x=0;
LOOPB(i,0,k){
    sum1+=price[i];
    sum2+=price[i];
    if(i>=n)sum1-=price[i-n];
    if(i>=m)sum2-=price[i-m];
    av1=sum1/n;
    av2=sum2/m;
    if(av1<av2){
        if((f==-1||i==n-1)&&i>=n-1){printf("BUY ON DAY %d\n",i+1);}
        if(i>=n-1)f=1;
    }else if(av1>av2){
        if((f==1||i==n-1)&&i>=n-1){printf("SELL ON DAY %d\n",i+1);}
        if(i>=n-1)f=-1;
    }else
        f=0;

}

}
