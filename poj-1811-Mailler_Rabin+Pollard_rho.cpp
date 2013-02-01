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
int i,j,k,a,m,n,s,t,l,tt,cas;
typedef long long int LLI;
LLI ans;

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
    LLI d=1,tmp=a%n;
    while(b){
        if(b&1)
            d=mulmod(d,tmp,n);
        tmp=mulmod(tmp,tmp,n);
        b>>=1;
    }
    return d;
}

inline LLI gcd(LLI a,LLI b){
    LLI r;
    while(b){
        r=b;
        b=a%b;
        a=r;
    }
    return a;
}

inline bool witness(const LLI& a,const LLI& n,int t,const LLI& u){
    LLI x,y;
    x=powmod(a,u,n);
    while(t--){
        y=mulmod(x,x,n);
        if(y==1&&x!=1&&x!=n-1)
            return true;
        x=y;
    }
    return y!=1;
}


inline bool Miller_Rabin(const LLI& n,int times){
    if(n==1)return false;
    if(n==2)return true;
    if(!(n&1))return false;
    LLI a,u=n-1;
    int t=0;
    while(!(u&1)){
        t++;
        u>>=1;
    }
    while(times--){
        a=rand()%(n-1)+1;
        if(witness(a,n,t,u))
            return false;
    }
    return true;
}


inline LLI pollard_rho(const LLI& c,const LLI& num){
    int i=1,k=2;
    LLI x=rand()%num;
    LLI y=x,comDiv;
    do{
        i++;
        if((x=mulmod(x,x,num)-c)<0){
            x+=num;
        }
        if(x==y)break;
        comDiv=gcd((y-x+num)%num,num);
        if(comDiv>1&&comDiv<num)
            return comDiv;
        if(i==k){
            y=x;
            k<<=1;
        }
    }while(1);
    return num;
}

void findfactor(const LLI& num){
    if(Miller_Rabin(num,2)){
        ans=MIN(num,ans);
        return;
    }
    LLI factor;
    do{
        factor=pollard_rho(rand()%(num-1)+1,num);
    }while(factor>=num);
    findfactor(factor);
    findfactor(num/factor);
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&cas);
LLI n;
while(cas--){
    scanf("%I64d",&n);
    ans=n;
    findfactor(n);
    if(ans==n){
        printf("Prime\n");
    }else{
        printf("%I64d\n",ans);
    }
}
}
