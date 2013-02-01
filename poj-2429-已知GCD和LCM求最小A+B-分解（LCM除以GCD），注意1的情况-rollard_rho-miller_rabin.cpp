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
const unsigned long long int ULLOO=1LL<<63;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,l,tt,cas;
typedef unsigned long long int ULL;
ULL GCD,LCM,KEY,ANS,A,B;
vector<ULL> num;
vector<ULL> factors,counts;
inline ULL gcd(ULL a,ULL b){
    ULL c;
    while(b){
        c=b;
        b=a%b;
        a=c;
    }
    return a;
}

inline ULL mulmod(const ULL& a, ULL b,const ULL& n){
    ULL ret=0,tmp=a%n;
    while(b){
        if(b&1)
            if((ret+=tmp)>n)
                ret-=n;
        if((tmp<<=1)>n)
            tmp-=n;
        b>>=1;
    }
    return ret;
}

inline ULL powmod(const ULL& a,ULL b,const ULL& n){
    ULL ret=1,tmp=a%n;
    while(b){
        if(b&1)
            ret=mulmod(tmp,ret,n);
        tmp=mulmod(tmp,tmp,n);
        b>>=1;
    }
    return ret;
}

inline ULL pollard_rho(const ULL& n,const ULL& c){
    ULL x=rand()%n,d;
    ULL y=x,i=1,k=2;
    while(1){
        i++;
        if((x=mulmod(x,x,n)-c)<0)
            x+=n;
        if(y==x)
            return n;
        d=gcd((y-x+n)%n,n);
        if(d>1&&d<n)
            return d;
        if(i==k){
            y=x;
            k<<=1;
        }
    }
}

inline bool witness(const ULL& a,const ULL& n,int t,const ULL& u){
    ULL x,y;
    x=powmod(a,u,n);
    while(t--){
        y=mulmod(x,x,n);
        if(y==1&&x!=1&&x!=n-1)
            return true;
        x=y;
    }
    return y!=1;
}

inline bool miller_rabin(const ULL& n,int times){
    if(n==2)return true;
    if(n==1||!(n&1))return false;
    int t=0;
    ULL u=n-1,a;
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

inline void findfactor(const ULL& n){
    if(n==1){num.push_back(1);return;}
    if(miller_rabin(n,3)){
        num.push_back(n);
        return;
    }
    ULL fa;
    do{
        fa=pollard_rho(n,rand()%(n-1)+1);
    }while(fa>=n);
    findfactor(fa);
    findfactor(n/fa);
}

void dfs(int step,ULL now){
    if(step==factors.size()){
        ULL a=now,b=KEY/now;
        if(gcd(a,b)==1){
            a*=GCD;
            b*=GCD;
            if(a+b<ANS){
                ANS=a+b;
                A=MIN(a,b);
                B=MAX(a,b);
            }
        }
        return;
    }
    int i;
    LOOP(i,0,counts[step]){
        if(now>ANS)return;
        dfs(step+1,now);
        now*=factors[step];
    }
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif

while(scanf("%I64u%I64u",&GCD,&LCM)!=EOF){
    num.clear();
    factors.clear();
    counts.clear();
    KEY=LCM/GCD;
    findfactor(KEY);
    sort(num.begin(),num.end());
    for(i=0;i!=num.size();){
        factors.push_back(num[i]);
        counts.push_back(1);
        i++;
        while(i!=num.size()&&num[i]==num[i-1]){
            counts[counts.size()-1]++;
            i++;
        }
    }
    ANS=ULLOO;
    dfs(0,1);
    cout<<A<<' '<<B<<endl;
}
}
