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
typedef long long int ull;

inline ull gcd(ull a,ull b){
    ull c;
    while(b){
        c=b;
        b=a%b;
        a=c;
    }
    return a;
}

inline ull pow(ull a,ull b){
    ull tmp=a,ret=1;
    while(b){
        if(b&1)ret*=tmp;
        tmp*=tmp;
        b>>=1;
    }
    return ret;
}

inline ull polya(ull c,ull s){
    if(!s)return s;
    int i;
    ull ans=0;
    LOOP(i,1,s)
        ans+=pow((ull)c,gcd((ull)i,s));
    if(s&1)
        ans+=s*pow((ull)c,(ull)(s>>1)+1);
    else
        ans+=(s>>1)*(pow((ull)c,(ull)s>>1)+pow((ull)c,(s>>1)+1));
    return ans/(s<<1);
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&n);
while(n!=-1){
    printf("%I64u\n",polya((ull)3,(ull)n));
    scanf("%d",&n);
}
}
