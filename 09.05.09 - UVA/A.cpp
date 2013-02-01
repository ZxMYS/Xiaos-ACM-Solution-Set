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
int i,j,kk,kkk,k,a,m,n,p,nn,mm,pp,s,t,l,tt,cas;
float x[102],y[102],z[102];
float juzhen[2],ans;
float matrix[2];
float xx[2],t1,t2;
inline void matrixmul(float a[2],float b[2],float c[2]){
    xx[0]=a[0]*b[0]+a[1]*b[1];
    xx[1]=a[0]*b[1]+a[1]*b[0];
    c[0]=xx[0];
    c[1]=xx[1];
}

inline void ksm(){
    kkk=kk-1;
    matrix[1]=juzhen[1];
    matrix[0]=juzhen[0];
    while(kkk){
        if(kkk&1)
            matrixmul(matrix,juzhen,juzhen);
        matrixmul(matrix,matrix,matrix);
        kkk>>=1;
    }
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
    printf("Case %d: ",++l);
    scanf("%d%d%d%d",&n,&m,&p,&kk);
    ans=0;
    nn=(n>>1)+((n&1)?1:0);
    mm=(m>>1)+((m&1)?1:0);
    pp=(p>>1)+((p&1)?1:0);
    LOOPB(i,0,nn)
    {
                t1 = (float) i/n;
                t2 = (float)(n - i - 1)/n;
                x[n-i-1]=x[i] = 1 - t1*t1 - t2*t2;
    }
    LOOPB(i,0,mm)
    {
                t1 = (float) i/m;
                t2 = (float)(m - i - 1)/m;
                y[m-i-1]=y[i] = 1 - t1*t1 - t2*t2;
    }
    LOOPB(i,0,pp)
    {
                t1 = (float) i/p;
                t2 = (float)(p - i - 1)/p;
                z[p-i-1]=z[i] = 1 - t1*t1 - t2*t2;
    }
    tt=1;
    if(!(n&1)){
        n>>=1;
        tt<<=1;
    }
    if(!(m&1)){
        m>>=1;
        tt<<=1;
    }
    if(!(p&1)){
        p>>=1;
        tt<<=1;
    }
    LOOPB(i,0,n)
        LOOPB(j,0,m)
            LOOPB(k,0,p){
                juzhen[1]=x[i]*y[j]*z[k];
                juzhen[0]=1-juzhen[1];
                ksm();
                ans+=juzhen[1];
        }
    cout<<ans*tt<<endl;
}
}
