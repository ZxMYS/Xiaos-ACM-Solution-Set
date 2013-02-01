#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
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
const int oo=1<<29;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,s,t,l,tt,cas;

typedef long long LLI;
LLI n;
LLI M=1000000007LL;
inline LLI mulmod(const LLI& a,LLI b,const LLI& n){
    LLI back=0,tmp=a%n;
    while(b){
        if((b&1)&&(back+=tmp)>n)
            back-=n;
        if((tmp<<=1)>n)
            tmp-=n;
        b>>=1;
    }
    return back;
}

inline LLI powmod(const LLI& a,LLI b,const LLI& n){
    LLI d=1;
    LLI tmp=a%n;
    while(b){
        if(b&1)
            d=mulmod(d,tmp,n);
        tmp=mulmod(tmp,tmp,n);
        b>>=1;
    }
    return d;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&cas);
l=0;
while(cas--){
    printf("Case #%d: ",++l);
    scanf("%lld",&n);
    if(n==1){
        printf("1\n");
        continue;
    }
    LLI TT_TT;
	n--;
	LLI xiaobaiTWO=2;
    TT_TT=powmod(xiaobaiTWO,n,M);
	n++;
    TT_TT=mulmod(TT_TT,n,M);
    printf("%lld\n",TT_TT);
}
}
