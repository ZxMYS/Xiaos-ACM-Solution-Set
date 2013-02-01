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
const int MAXN=10000005;
const int oo=1<<29;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,m,n,s,t,l,tt,cas;
typedef unsigned long long int ULL;
ULL ans,a,b;
typedef struct{int val,op;} numtype;
vector<int> prime;
vector<numtype> num;

inline ULL F(ULL a,ULL b){
    return a*b+a-((a*a+a)>>1);
}

inline void getSqrtFreeNumber(){
    int tmp,count;
    numtype numtmp;
    LOOP(i,2,MAXN){
        tmp=i;
        count=0;
        for(j=0;j<prime.size()&&tmp>=prime[j];j++){
            if(!(tmp%prime[j])){
                tmp/=prime[j];
                if(!(tmp%prime[j]))
                    goto L1;
                count++;
            }
        }
        if(count&1)
            numtmp.op=1;
        else
            numtmp.op=-1;
        numtmp.val=i;
        num.push_back(numtmp);
    L1:;
    }
}

inline void getPrime(){
    bool num[MAXN+1];
    memset(num,1,sizeof(num));
    LOOP(i,2,MAXN){
        if(num[i]){
            j=i<<1;
            while(j<=MAXN){
                num[j]=0;
                j+=i;
            }
        }
    }
    LOOP(i,2,MAXN){
        if(num[i])
            prime.push_back(i);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
getPrime();
getSqrtFreeNumber();
scanf("%d",&cas);
l=0;
while(cas--){
    ans=0;
    scanf("%d%d",&n,&m);
    if(n>m){
        n=n^m;
        m=n^m;
        n=n^m;
    }
    int nn=n,mm=m;
    ULL ans2=0;
    LOOPB(t,0,prime.size()){
        ans=0;
        n=nn;m=mm;
        k=prime[t];
        n/=k;
        m/=k;
        if(!n||!m)
            break;
        for(i=0;i<num.size()&&num[i].val<=n;i++){
            a=n/num[i].val;
            b=m/num[i].val;
            ans+=F(a,b)*num[i].op;
        }
        ans=F(n,m)-ans;
        ans2+=((ans-1)<<1)+1;
    }
    cout<<ans2<<endl;
}
}
