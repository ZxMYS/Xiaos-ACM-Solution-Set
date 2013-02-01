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
int i,j,k,a,m,n,s,t,l,tt,cas,c;
double ga[111][111], ga2[111][111],v[111],ret[111];

inline void out(){
    int i,j;
    LOOP(i,0,c){
        LOOP(j,0,c)
            printf("%.5lf ",ga[i][j]);
        cout<<endl;
    }
    cout<<endl;
}

inline void out2(){
    int i;
    LOOP(i,0,c)
        printf("%.5lf ",v[i]);
    cout<<endl<<endl;
}

inline void mul(double m1[111][111],double m2[111][111]){
    LOOP(i,0,c)
        memset(ga2[i],0,sizeof(ga2[i]));
    LOOP(i,0,c){
        LOOP(j,0,c){
            LOOP(k,0,c){
                ga2[i][j]+=m1[i][k]*m2[k][j];
            }
        }
    }
    LOOP(i,0,c)
        LOOP(j,0,c)
            m2[i][j]=ga2[i][j];
}

inline void mul2(double m1[111][111],double m2[111]){
    memset(ret,0,sizeof(ret));
    LOOP(i,0,c)
        LOOP(k,0,c)
            ret[i]+=m1[i][k]*m2[k];
    LOOP(i,0,c)
        m2[i]=ret[i];
}


inline void solve(){
    while(n){
        if(n&1){
            mul2(ga,v);
        }
        mul(ga,ga);
        out();
        n>>=1;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&c);
while(c){
    scanf("%d%d",&n,&m);
    if(c==0&&m==0){
        printf("0\n");
        goto L1;
    }
    if(m>c||c==0){
        printf("0\n");
        goto L1;
    }
    LOOP(i,0,c)
        memset(ga[i],0,sizeof(ga[i]));
    LOOP(i,0,c){
        if(i-1>=0){
            ga[i-1][i]+=i*1.0/c;
        }
        if(i+1<=c){
            ga[i+1][i]+=1-i*1.0/c;
        }
    }
    out();
    memset(v,0,sizeof(v));
    v[0]=1;
    solve();
    printf("%.3lf\n",v[m]);
    L1:
    scanf("%d",&c);
}
}
