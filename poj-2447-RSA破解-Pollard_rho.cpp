#include<stdio.h>
#include<stdlib.h>
#include<iostream>
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
typedef unsigned long long int LLI;
LLI C,N,E,D,P,Q,T,M,X,Y;

inline LLI gcd(LLI a,LLI b){
    LLI r;
    while(b){
        r=b;
        b=a%b;
        a=r;
    }
    return a;
}

inline LLI mulmod(const LLI& a,LLI b,const LLI& n){
    LLI back=0,tmp=a%n;
    while(b){
        if((b&1))
            if((back+=tmp)>n)
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
            d=mulmod(tmp,d,n);
        tmp=mulmod(tmp,tmp,n);
        b>>=1;
    }
    return d;
}

inline LLI pollard_rho(const LLI& n,const LLI& c){
    LLI d,x=rand()%n;
    LLI y=x;
    int i=1,k=2;
    while(1){
        i++;
        if((x=mulmod(x,x,n)-c)<0)
            x+=n;
        if(x==y)break;
        d=gcd((y-x+n)%n,n);
        if(d>1&&d<n)
            return d;
        if(i==k){
            y=x;
            k<<=1;
        }
    }
    return n;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
while(scanf("%I64u%I64u%I64u",&C,&E,&N)!=EOF){
    P=pollard_rho(N,rand()%(n-1)+1);
    T=(P-1)*(N/P-1);
    i=1;
    while(1)
        {
            if(!((T*i+1) % E))
            {
                D=(T*i+1)/E;
                M=powmod(C,D,N);
                if(powmod(M,E,N) == C)break;
            }
            ++i;
        }
    //printf("Private Key:%I64u\n",D);
    printf("%I64u\n",M);
}
}
