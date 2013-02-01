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
typedef long long int LLI;
const int oo=1<<29;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,a,b,m,n,s,tt,cas,min_tt,min_i;
double k,ans,t;
int f[1010];
LLI pa,pb,l,fenzi,fenmu;

inline LLI gcd(LLI x,LLI y){
    while(x){
        x%=y^=x^=y^=x;
    }
    return y;
}

inline double deal(){
    double ret=0,fetch;
    int i,j;
    LOOPB(i,0,n){
        fetch=j=0;
        while(fetch<f[i]&&j<=3){
            fetch+=k;
            j++;
        }
        if(j>3)return oo;
        ret+=a*(fetch-f[i])+b*j;
    }
    return ret;
}

inline void calc(){
    pa=pb=0;
    double fetch;
    int i,j;
    LOOPB(i,0,n){
        fetch=j=0;
        while(fetch<f[i]){
            fetch+=k;
            j++;
        }
        pa+=j*(LLI)f[min_i]-f[i]*(LLI)min_tt;
        pb+=j;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&n);
while(n){
    ans=oo;
    scanf("%d%d",&a,&b);
    LOOPB(i,0,n)
        scanf("%d",&f[i]);
    LOOPB(tt,1,20){
        LOOPB(i,0,n){
            k=(double)f[i]/(double)tt;
            t=deal();
            if(ans>t){
                ans=t;
                min_tt=tt;
                min_i=i;
            }
        }
    }
    k=(double)f[min_i]/(double)min_tt;
    calc();
    fenmu=min_tt;
    fenzi=a*pa+b*pb*fenmu;
    l=gcd(fenzi,fenmu);
    while(l!=1){
        fenzi/=l;
        fenmu/=l;
        l=gcd(fenzi,fenmu);
    }
    if(fenmu!=1)
        cout<<fenzi<<" / "<<fenmu<<endl;
    else
        cout<<fenzi<<endl;
    scanf("%d",&n);
}
}
