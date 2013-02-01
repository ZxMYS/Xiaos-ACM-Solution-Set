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
#define EPS 0.00001
const int oo=1<<29;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,l,tt,cas,ans;
bool isPrime[500001];
int factors[500001];
int min_fa[500001];
int min_fa_exp[500001];
int Prime[41540],pt;
bool flag,flag1;

inline int mulmod(const int& a,int b,const int& n){
    int back=0,tmp=a%n;
    while(b){
        if((b&1)&&(back+=tmp)>n){
            back-=n;
        }
        if((tmp<<=1)>n){
            tmp-=n;
        }
        b>>=1;
    }
    return back;
}

inline int powmod(const int& a,int b,const int& n){
    int d=1,tmp=a%n;
    while(b){
        if(b&1){
            d=mulmod(d,tmp,n);
        }
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
memset(isPrime,1,sizeof(isPrime));
factors[1]=1;
LOOP(i,2,500000){
    if(isPrime[i]){
        Prime[pt++]=i;
        min_fa[i]=factors[i]=1;
        if(i*1LL*i<=500000){
            for(j=i*i;j<=500000;j+=i){
                isPrime[j]=false;
                min_fa_exp[j]=0;
                if(min_fa[j]==0||min_fa[j]>i){
                    min_fa[j]=i;
                }
            }
        }
    }
}
LOOP(i,2,500000){
    if(isPrime[i]){
        min_fa_exp[i]=1;
    }else{
        m=i;
        s=1;
        while(!(m%min_fa[i])){
            m/=min_fa[i];
            min_fa_exp[i]++;
            s*=min_fa[i];
        }
        min_fa[i]=s;
    }
}
LOOP(i,2,500000){
    factors[i]=(min_fa_exp[i]+1)*factors[i/min_fa[i]];
}
scanf("%d",&cas);
while(cas--){
    tt=1;
    flag=false;
    scanf("%d",&n);
    if(isPrime[n]){
        printf("1\n");
        continue;
    }
    m=n;
    tt=factors[n];
    if(tt&1){
        n=(int)(sqrt((double)n)+EPS);
        tt-=2;
        
        t=tt;
        s=1;
        while(t--){
            s*=n;
            if(s>=10000){
                flag=true;
                break;
            }
        }
        
        if(tt)
            ans=powmod(n,tt,10000);
        else
            ans=1;
    }else{
        tt>>=1;
        tt-=1;

        t=tt;
        s=1;
        while(t--){
            s*=n;
            if(s>=10000){
                flag=true;
                break;
            }
        }
        
        if(tt)
            ans=powmod(n,tt,10000);
        else
            ans=1;
    }
    if(ans>=10000){
        flag=true;
        ans%=10000;
    }
    n=m;
    if(!flag||ans>=1000){
        printf("%d\n",ans);
    }
    else{
        printf("0");
        if(ans<100)
            printf("0");
        if(ans<10)
            printf("0");
        printf("%d\n",ans);
    }
}
}
